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

ll const plim = 801;
ld dp[201][plim];
ld sumdp[plim];

bool comp(int i, int j){
    return dist[i] < dist[j];
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
    assert(n <= 200 && m <= 400);
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
        if(ind[c1] == s)break;
        for(int c2 = 0; c2 < plim; c2++){
            sumdp[c2] = 0.0;
            for(int c3 = 0; c3 < n; c3++){
                a = ind[c3];
                if(c3 <= c1){
                    dp[a][c2] = (dist[a] == c2);
                }
                else{
                    if(c2 > 0)dp[a][c2] = sumdp[c2-1]/ld(n);
                }
                sumdp[c2] += dp[a][c2];
            }
        }
        ld exp = 0;
        for(int c2 = 0; c2 < plim; c2++){
            exp += c2*dp[s][c2];
        }
        ans = min(ans,exp);
    }

    cout << setprecision(18) << ans << "\n";

    return 0;
}
