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
vl A;

int DP[101][20001] = {0};
bool DPC[101][20001] = {0};

int dp(int i, int dist){
    int dist2 = dist-10000;
    if(i == m)return abs(dist2);
    if(DPC[i][dist])return DP[i][dist];
    int d = A[i+1]-A[i];
    int ans = min((d+n)%n + dp(i+1,dist+(d+n)%n) , (n-d)%n + dp(i+1,dist-(n-d)%n));
    DPC[i][dist] = 1;
    DP[i][dist] = ans;
    return ans;
}

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;
    cin >> n >> m;
    assert(n <= 10 && m <= 10);
    A.push_back(0);
    for(int c1 = 0; c1 < m; c1++){
        cin >> a;
        a--;
        A.push_back(a);
    }
    cout << dp(0,10000) << "\n";

    return 0;
}

