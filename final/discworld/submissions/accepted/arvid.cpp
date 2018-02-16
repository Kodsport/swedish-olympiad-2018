#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define all(v) v.begin(), v.end()
#define rep(i, from, to) for (ll i = from; i < ll(to); ++i)

vector<vector<vii>> graph;
vector<vi> m;
vector<vi> p;

ll oo = ll(1e9)*ll(1e9);
ll n,k;

ll id(ii x){
    return (n*x.first+x.second);
}
ii rid(ll x) {
    ii pai = {x/n, x%n};
    return pai;
}

vector<vii> backtrack;

ll dijkstra(ii source, ii target) {
    vector<ll> min_distance( n*n, oo);
    min_distance[id(source)] = 0;
    set<pair<ll, ii>> active_vertices;
    active_vertices.insert({0,source});
        
    while (!active_vertices.empty()) {
        ii where = active_vertices.begin()->second;
        //cout << "considering:"<<where.first<<","<<where.second<<endl;
        //cout << "nghs:" << graph[where.first][where.second].size()<<endl;
        if (where == target) return min_distance[id(where)];
        active_vertices.erase( active_vertices.begin() );
        for (auto ng : graph[where.first][where.second]) 
            if (min_distance[id(ng)] > min_distance[id(where)] + m[where.first][where.second]) {
                active_vertices.erase( { min_distance[id(ng)], ng} );
                min_distance[id(ng)] = min_distance[id(where)] + m[where.first][where.second];
                backtrack[ng.first][ng.second] = where;
                active_vertices.insert( { min_distance[id(ng)], ng} );
            }
    }
    assert(false);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    ll t;
    cin>>t;
    if (t==5) {
        cin>>n>>k;
        m.resize(n, vi(n));
        p.resize(n, vi(n));
        backtrack.resize(n, vii(n));
        rep(i,0,n) rep(j,0,n) {
            cin >> m[i][j];
        }
        rep(i,0,n) rep(j,0,n) {
            cin >> p[i][j];
        }
        graph.resize(n, vector<vii>(n));
        rep(i,0,n) rep(j,0,n) {
            if (m[i][j] == -1) continue;
            if (i > 0) {
                if (m[i-1][j] != -1) {
                    graph[i][j].push_back({i-1,j});
                }
            }
            if (j > 0) {
                if (m[i][j-1] != -1) {
                    graph[i][j].push_back({i,j-1});
                }
            }
            if (i < n-1) {
                if (m[i+1][j] != -1) {
                    graph[i][j].push_back({i+1,j});
                }
            }
            if (j < n-1) {
                if (m[i][j+1] != -1) {
                    graph[i][j].push_back({i,j+1});
                }
            }
        }
        vector<vi> res(n,vi(n));
        vii interestpoints;
        interestpoints.push_back({n-1,(n-1)/2});
        interestpoints.push_back({n-2,(n-1)/2});
        interestpoints.push_back({0,(n-1)/2});
        interestpoints.push_back({1,(n-1)/2});
        ll minp = ll(1e9)*ll(1e9);
        ii removeind;
        for(auto& ind:interestpoints){
            if (p[ind.first][ind.second]<minp){
                minp=p[ind.first][ind.second];
                removeind=ind;
            }
        }
        rep(i,0,6){
            vector<pair<ll,ii>> newpo;
            dijkstra({0,(n-1)/2},{n-1,(n-1)/2});
            ii vx = {n-1,(n-1)/2};
            while (vx != make_pair(0ll,(n-1)/2)){
                vx = backtrack[vx.first][vx.second];
                newpo.push_back({p[vx.first][vx.second], vx});
            }
            sort(all(newpo));
            rep(j,0,newpo.size()) {
                if (newpo[j].first < minp){
                    ll grab = min(1ll,k/newpo[j].first);
                    k-=grab*newpo[j].first;
                    res[newpo[j].second.first][newpo[j].second.second] += grab*newpo[j].first;
                    m[newpo[j].second.first][newpo[j].second.second] += grab;
                }
            }
        }
     
        while (k > 0) {
            //cout <<p[removeind.first][removeind.second]<<endl;
            k-=p[removeind.first][removeind.second];
            if (k>=0){
                res[removeind.first][removeind.second] += p[removeind.first][removeind.second];
                m[removeind.first][removeind.second]++;
            }
                
        }
        rep(i,0,n) {
            rep(j,0,n) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    } else if (t!=4) {
        cin>>n>>k;
        m.resize(n, vi(n));
        p.resize(n, vi(n));
        backtrack.resize(n, vii(n));
        rep(i,0,n) rep(j,0,n) {
            cin >> m[i][j];
        }
        rep(i,0,n) rep(j,0,n) {
            cin >> p[i][j];
        }
        graph.resize(n, vector<vii>(n));
        rep(i,0,n) rep(j,0,n) {
            if (m[i][j] == -1) continue;
            if (i > 0) {
                if (m[i-1][j] != -1) {
                    graph[i][j].push_back({i-1,j});
                }
            }
            if (j > 0) {
                if (m[i][j-1] != -1) {
                    graph[i][j].push_back({i,j-1});
                }
            }
            if (i < n-1) {
                if (m[i+1][j] != -1) {
                    graph[i][j].push_back({i+1,j});
                }
            }
            if (j < n-1) {
                if (m[i][j+1] != -1) {
                    graph[i][j].push_back({i,j+1});
                }
            }
        }
        vector<vi> res(n,vi(n));
        vii interestpoints;
        interestpoints.push_back({n-1,(n-1)/2});
        interestpoints.push_back({n-2,(n-1)/2});
        interestpoints.push_back({0,(n-1)/2});
        interestpoints.push_back({1,(n-1)/2});
        ll minp = ll(1e9)*ll(1e9);
        ii removeind;
        for(auto& ind:interestpoints){
            if (p[ind.first][ind.second]<minp){
                minp=p[ind.first][ind.second];
                removeind=ind;
            }
        }
        while (k > 0) {
            //cout <<p[removeind.first][removeind.second]<<endl;
            k-=p[removeind.first][removeind.second];
            if (k>=0){
                res[removeind.first][removeind.second] += p[removeind.first][removeind.second];
                m[removeind.first][removeind.second]++;
            }
                
        }
        rep(i,0,n) {
            rep(j,0,n) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    }
    cin>>n>>k;
    m.resize(n, vi(n));
    p.resize(n, vi(n));
    backtrack.resize(n, vii(n));
    rep(i,0,n) rep(j,0,n) {
        cin >> m[i][j];
    }
    rep(i,0,n) rep(j,0,n) {
        cin >> p[i][j];
    }
    graph.resize(n, vector<vii>(n));
    rep(i,0,n) rep(j,0,n) {
        if (m[i][j] == -1) continue;
        if (i > 0) {
            if (m[i-1][j] != -1) {
                graph[i][j].push_back({i-1,j});
            }
        }
        if (j > 0) {
            if (m[i][j-1] != -1) {
                graph[i][j].push_back({i,j-1});
            }
        }
        if (i < n-1) {
            if (m[i+1][j] != -1) {
                graph[i][j].push_back({i+1,j});
            }
        }
        if (j < n-1) {
            if (m[i][j+1] != -1) {
                graph[i][j].push_back({i,j+1});
            }
        }
    }
    vector<vi> res(n,vi(n));
    vii interestpoints;
    interestpoints.push_back({n-1,(n-1)/2});
    interestpoints.push_back({n-2,(n-1)/2});
    interestpoints.push_back({0,(n-1)/2});
    interestpoints.push_back({1,(n-1)/2});
    ll minp = ll(1e9)*ll(1e9);
    ii removeind;
    for(auto& ind:interestpoints){
        if (p[ind.first][ind.second]<minp){
            minp=p[ind.first][ind.second];
            removeind=ind;
        }
    }
    rep(i,0,7){
        vector<pair<ll,ii>> newpo;
        dijkstra({0,(n-1)/2},{n-1,(n-1)/2});
        ii vx = {n-1,(n-1)/2};
        while (vx != make_pair(0ll,(n-1)/2)){
            vx = backtrack[vx.first][vx.second];
            newpo.push_back({p[vx.first][vx.second], vx});
        }
        sort(all(newpo));
        rep(j,0,newpo.size()) {
            if (newpo[j].first < minp){
                ll grab = min(20ll,k/newpo[j].first);
                k-=grab*newpo[j].first;
                res[newpo[j].second.first][newpo[j].second.second] += grab*newpo[j].first;
                m[newpo[j].second.first][newpo[j].second.second] += grab;
            }
        }
    }
 
    while (k > 0) {
        //cout <<p[removeind.first][removeind.second]<<endl;
        k-=p[removeind.first][removeind.second];
        if (k>=0){
            res[removeind.first][removeind.second] += p[removeind.first][removeind.second];
            m[removeind.first][removeind.second]++;
        }
            
    }
    rep(i,0,n) {
        rep(j,0,n) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }











    return 0;
}

