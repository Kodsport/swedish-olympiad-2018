#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
ll n,k;

vl A,CS1,CS2;

ll DP[400001] = {0};
bool DPC[400001] = {0};

ll dp(ll i){
    if(i == n-1)return A[n-1];
    if(DPC[i])return DP[i];
    ll ans = CS2[n] - CS2[i] - CS1[i]*(n-i);
    for(int c1 = i+1; c1 < n; c1++){
        ans = min(ans, k + CS2[c1]-CS2[i]-CS1[i]*(c1-i)+dp(c1));
    }
    DPC[i] = 1;
    DP[i] = ans;
    return ans;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c;
    cin >> n >> k;
    assert(n <= 1000);
    ll sum = 0;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        sum += a;
    }
    CS1.push_back(0);
    for(int c1 = 0; c1 < n; c1++){
        CS1.push_back(CS1[c1]+A[c1]);
    }
    ll cs = 0;
    for(int c1 = 0; c1 < n+1; c1++){
        cs += CS1[c1];
        CS2.push_back(cs);
    }
    cout << dp(0) << "\n";
    return 0;
}

