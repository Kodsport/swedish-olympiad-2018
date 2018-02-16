#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
ll n,m,k,T,q;

ll s,t;

vector<vi> C(100001, vi());
ll dist[100001] = {0};
vi ind;
bool mark[100001] = {0};
ll lim = 20000;

bool comp(int i, int j){
    return dist[i] < dist[j];
}

ld test(ll i){
    for(int c1 = 0; c1 < n; c1++){
        mark[ind[c1]] = (c1 < i);
    }
    ld sum = 0.0;
    for(int c1 = 0; c1 < lim; c1++){
        int i = s;
        while(i != t){
            if(mark[i]){
                sum += dist[i];
                break;
            }
            else{
                sum += 1.0;
                i = rand()%n;
            }
        }
    }
    return sum/ld(lim);
}

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> m;
    cin >> s >> t;
    s--;
    t--;
    for(int c1 = 0; c1 < n; c1++){
        dist[c1] = n;
        ind.push_back(c1);
    }
    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }

    queue<ll> Q;
    Q.push(t);
    dist[t] = 0;
    while(!Q.empty()){
        a = Q.front();
        Q.pop();
        for(int c1 = 0; c1 < sz(C[a]); c1++){
            b = C[a][c1];
            if(dist[b] == n){
                dist[b] = dist[a]+1;
                Q.push(b);
            }
        }
    }
    sort(all(ind),comp);
    ld ans = dist[s];

    for(int c1 = 0; c1 < n; c1++){
        if(ind[c1] == s)b = c1;
    }
    ll l = 1;
    ll r = b;
    while(l < r-1){

        ll mid1 = (2*l+r)/3;
        ll mid2 = (l+2*r)/3;

        if(l > r-4){
            for(int c1 = l; c1 <= r; c1++){
                ans = min(ans, test(c1));
            }
            break;
        }

        ld tst = test(mid1);
        ld tst2 = test(mid2);
        ans = min(ans,tst);
        ans = min(ans,tst2);
        //cerr << l << " " << r << "  -  " << tst << " " << tst2 << "\n";
        if(tst < tst2){
            r = mid2;
        }
        else{
            l = mid1;
        }
    }

    cout << setprecision(18) << ans << "\n";

    return 0;
}
