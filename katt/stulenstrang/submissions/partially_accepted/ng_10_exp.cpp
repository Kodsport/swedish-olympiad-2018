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

string s;
int F[26] = {0};

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> s;
    n = s.length();
    assert(n <= 20);
    m = 0;
    bool fail = 0;
    for(int c1 = 0; c1 < n; c1++){
        m = max(m, s[c1]-'a'+1);
        F[s[c1]-'a']++;
    }
    for(int c1 = 0; c1 < 26; c1++){
        if(F[c1]%2 == 1)fail = 1;
    }
    if(fail){
        cout << "-1\n";
        return 0;
    }
    ll ans = m;
    for(int c1 = 0; c1 < (1 << n); c1++){
        ll cuts = 0;
        ll prev = -1;
        ll F2[26] = {0};
        for(int c2 = 0; c2 < n; c2++){
            bool bit = ((c1&(1 << c2))!=0);
            if(bit != prev && prev != -1)cuts++;
            if(bit)F2[s[c2]-'a']++;
            prev = bit;
        }
        bool yes = 1;
        for(int c2 = 0; c2 < m; c2++){
            if(F2[c2] != F[c2]/2)yes = 0;
        }
        if(yes){
            ans = min(ans,cuts);
        }
    }
    cout << ans << "\n";

    return 0;
}
