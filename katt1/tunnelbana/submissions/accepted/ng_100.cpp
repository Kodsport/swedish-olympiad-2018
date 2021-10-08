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

struct Tree{
    vector<vector<int> > C;
    vector<int> line;
    vector<int> labels;
    vector<int> invlabels;
    vector<int> depth;
    vector<int> FL;
    vector<int> PAR;
    vector<int> CS;
    vector<vector<int> > ST;
    int d = 0;

    void dfs(int i, int par){
        PAR[i] = par;
        if(labels[i] == -1){
            labels[i] = d;
            invlabels.push_back(i);
            FL[i] = line.size();
            d++;
        }
        int l = labels[i];
        line.push_back(l);
        for(int c1 = 0; c1 < C[i].size(); c1++){
            int j = C[i][c1];
            if(j != par){
                depth[j] = depth[i] + 1;
                dfs(j,i);
                line.push_back(l);
            }
        }
    }

    int lca(int i, int j){
        int a = min(FL[i],FL[j]);
        int b = max(FL[i],FL[j]);
        int dep = 31 - __builtin_clz(b+1-a);
        int l = min(ST[dep][a] , ST[dep][b + 1 - (1 << dep)]);
        return invlabels[l];
    }

    int dist(int i, int j){
        return depth[i]+depth[j]-2*depth[lca(i,j)];
    }

    void setup(){
        for(int c1 = 0; c1 < C.size(); c1++){
            labels.push_back(-1);
            depth.push_back(0);
            FL.push_back(0);
            PAR.push_back(-2);
            CS.push_back(0);
        }
        dfs(0,-1);
        int t = 1;
        int p = 1;
        while(t < line.size()){
            t *= 2;
            p++;
        }
        for(int c1 = 0; c1 < p; c1++){
            vector<int> V;
            ST.push_back(V);
        }
        int N = line.size();
        for(int c1 = 0; c1 < p; c1++){
            for(int c2 = 0; c2 < N; c2++){
                if(c1 == 0){
                    ST[c1].push_back(line[c2]);
                }
                else{
                    ST[c1].push_back(min(ST[c1-1][c2] , ST[c1-1][min(N-1 , c2 + (1 << (c1-1)))]));
                }
            }
        }
    }
};

Tree tr;
ll DP[100001] = {0};

ll ans = 0;
ll sum = 0;

void dfs(int i, int par){
    for(int c1 = 0; c1 < sz(tr.C[i]); c1++){
        int a = tr.C[i][c1];
        if(a != par){
            dfs(a,i);
            tr.CS[i] += tr.CS[a];
        }
    }
    return;
}

ll dp(int i, int par){
    ll res = 0;
    ll res2 = 0;
    for(int c1 = 0; c1 < sz(tr.C[i]); c1++){
        int a = tr.C[i][c1];
        if(a != par){
            ll b = dp(a,i) + k - tr.CS[a];
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
    for(int c1 = 0; c1 < n; c1++){
        vi temp;
        tr.C.push_back(temp);
    }
    for(int c1 = 0; c1 < n-1; c1++){
        cin >> a >> b;
        a--;
        b--;
        tr.C[a].push_back(b);
        tr.C[b].push_back(a);
    }
    tr.setup();

    for(int c1 = 0; c1 < n; c1++)assert(tr.PAR[c1] != -2);

    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        a--;
        b--;
        tr.CS[a]++;
        tr.CS[b]++;
        c = tr.lca(a,b);
        if(c >= 0)tr.CS[c]-=2;
    }
    dfs(0,-1);

    for(int c1 = 0; c1 < n; c1++){
        sum += tr.CS[c1];
       // cout << c1+1 << "  " << tr.CS[c1] << "\n";
    }
    ans = sum;
    dp(0,-1);
    cout << ans << "\n";

    return 0;
}

