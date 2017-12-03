#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

    ll A, B;
    cin >> A >> B;

    pair<ll, pii> bs(1e18, pii(0, 0));
    rep(W,1,sqrt(B) + 2) {
        ll H = max(W, (A + W - 1) / W);
        if (A <= H * W && H * W <= B) bs = min(bs, make_pair(abs(H - W), pii(W, H)));
    }
    cout << bs.second.first << " " << bs.second.second << endl;
}
