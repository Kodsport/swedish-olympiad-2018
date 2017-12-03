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
	ll lo, hi;
	cin >> lo >> hi;
	ll a = (ll)round(sqrt(lo));
	if (a * a < lo) ++a;
	assert(a * a >= lo);
	if (a * a <= hi) {
		if ((a+1) * (a+1) <= hi) {
			cerr << "square, not unique" << endl;
			abort();
		}
		cout << a << ' ' << a << endl;
		return 0;
	}
	for (;;) {
		--a;
		assert(a >= 1);
		ll b = hi / a;
		assert(a <= b);
		assert(a * b <= hi);
		if (a * b >= lo) {
			if (a * (b-1) >= lo) {
				cerr << "non-square, not unique" << endl;
				abort();
			}
			cout << a << ' ' << b << endl;
			return 0;
		}
	}
}
