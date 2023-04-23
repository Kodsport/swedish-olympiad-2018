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
vl D;

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;
    cin >> n >> m;
    A.push_back(0);
    ll prev = 0;
    ll sumd = 0;
    for(int c1 = 0; c1 < m; c1++){
        cin >> a;
        a--;
        A.push_back(a);
        D.push_back((a-prev+n)%n);
        sumd += D[c1];
        prev = a;
    }
    sort(all(D));
    reverse(all(D));
    ll ans = 2*sumd;
    ll sum1 = sumd;
    ll sum2 = sumd;
    for(int c1 = 0; c1 < m; c1++){
        sum1 -= D[c1];
        sum1 += (n-D[c1])%n;
        sum2 -= n;
        ans = min(ans, sum1 + abs(sum2));
    }

    cout << ans << "\n";

    return 0;
}

