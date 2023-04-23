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
	if (N > 3000) return 0;
	vector<ll> a(N), dp(N+1);
	rep(i,0,N) cin >> a[i];
	rep(i,0,N) {
		ll& out = dp[i+1];
		ll acc = 0, best = LLONG_MAX;
		for (int j = i; j >= 0; --j) {
			acc += (i - j + 1) * a[j];
			best = min(best, acc + dp[j]);
		}
		out = resetCost + best;
	}
	cout << dp.back() - resetCost << endl;
	exit(0);
}
