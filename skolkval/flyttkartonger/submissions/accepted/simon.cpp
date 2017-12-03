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
	cin >> N;
	vi a(N);
	rep(i,0,N) cin >> a[i];
	auto works = [&](ll add) {
		vector<ll> temp(all(a));
		temp[0] += add;
		rep(i,0,N-1) {
			ll &a = temp[i], &b = temp[i+1];
			assert(a > 0 && b > 0);
			if (a < b) return false;
			ll c = (a + b) / 2, d = (a + b + 1) / 2;
			a = d; b = c;
		}
		return true;
	};

	ll lo = -1, hi = 1LL << 60;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (works(mid)) hi = mid;
		else lo = mid;
	}
	cout << hi << endl;
	exit(0);
}
