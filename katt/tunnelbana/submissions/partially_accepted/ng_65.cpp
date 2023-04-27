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

vector<vi> C(100001, vi());
ll kantvikt[100001] = {0};

ll PAR[100001] = {0};

ll sum = 0;
ll ans = 0;

void dfs1(int i, int par){
    PAR[i] = par;
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        int a = C[i][c1];
        if(a != par){
            dfs1(a,i);
        }
    }
    return;
}

bool dfs2(int i, int to, int par){
    if(i == to)return 1;
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        int a = C[i][c1];
        if(a != par){
            int j = a;
            if(a == PAR[i]){
                j = i;
            }
            kantvikt[j]++;
            bool b = dfs2(a,to,i);
            if(b)return 1;
            kantvikt[j]--;
        }
    }
    return 0;
}

ll dp(int i, int par){
    ll res = 0;
    ll res2 = 0;
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        int a = C[i][c1];
        if(a != par){
            ll b = dp(a,i) + k - kantvikt[a];
            if(b < res){
                res = b;
            }
            else{
                if(res < res2){
                    res2 = b;
                }
            }
        }
    }
    ans = min(ans, sum + res + res2);
    return res;
}

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> m >> k;
    assert(m <= 1000);
    for(int c1 = 0; c1 < n-1; c1++){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    dfs1(0,-1);
    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        a--;
        b--;
        dfs2(a,b,-1);
    }
    for(int c1 = 0; c1 < n; c1++){
        sum += kantvikt[c1];
    }
    ans = sum;
    dp(0,-1);
    cout << ans << "\n";
    return 0;
}

