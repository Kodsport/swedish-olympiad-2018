#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	ll resetCost;
	cin >> N >> resetCost;
	vector<ll> a(N);
	rep(i,0,N) cin >> a[i];

	if (N > 20)
		return 0;

	ll out = (ll)1e17;
	rep(d, 0, 1 << (N-1)) {
		ll ret = 0;
		ll rep = 0;
		rep(i, 0, N) {
			if ((d << 1) & (1<<i)) {
				rep = 0;
				ret += resetCost;
			}
			rep += a[i];
			ret += rep;
		}
		if (ret < out) out = ret;
	}

	cout << out << endl;
	return 0;
}
