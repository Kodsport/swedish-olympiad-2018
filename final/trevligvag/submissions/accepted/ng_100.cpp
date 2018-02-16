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
int n,m,k,T,q;

vector<vi> C(100001, vi());
vector<vi> CW(100001, vi());

double DP[100001] = {0};
int DPC[100001] = {0};
double diff = 0.0;
int now = 1;

double dp(ll i){
    if(i == n-1)return 0.0;
    if(DPC[i] == now)return DP[i];
    double ans = -big*big;
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        ans = max(ans, CW[i][c1] - diff + dp(C[i][c1]));
    }
    DPC[i] = now;
    DP[i] = ans;
    return ans;
}

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,d;

    scanf("%d", &n);
    scanf("%d", &m);
    for(int c1 = 0; c1 < m; c1++){
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        a--;
        b--;
        C[a].push_back(b);
        CW[a].push_back(c);
    }
    if(dp(0) < 0.0){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    now++;
    double l = 1.0;
    double r = 2000000.0;
    double lim = 0.000001;
    while((r-l)/l >= lim){
        double mid = sqrt(l*r);
        diff = mid;
        if(dp(0) >= 0.0){
            l = mid;
        }
        else{
            r = mid;
        }
        now++;
    }
    cout << setprecision(18) << sqrt(l*r) << "\n";
    return 0;
}
