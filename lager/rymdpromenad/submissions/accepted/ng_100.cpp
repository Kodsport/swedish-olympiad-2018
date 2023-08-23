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
vl D;
int main() {

   // ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> m;
    
    ll prev = 0;
    ll varv = 0;
    for(int c1 = 0; c1 < m; c1++){
        cin >> a;
        a--;
        D.push_back((a-prev+n)%n);
        varv += D[c1];
        prev = a;
    }
    D.push_back((n-prev)%n);
    varv += D[m];
    varv /= n;
    sort(all(D));
    reverse(all(D));
    ll ans = 0;
    for(int c1 = 0; c1 < m+1; c1++){
        if(c1 < varv){
            ans += n-D[c1];
        }
        else{
            ans += D[c1];
        }
    }
    cout << ans << "\n";
    return 0;
}
