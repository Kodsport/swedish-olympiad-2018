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
	assert(N <= 1000);
	vector<ll> a(N);
	vector<pair<ll, int>> dp(N+1);
	rep(i,0,N) cin >> a[i];
	deque<int> goodj;
	goodj.push_back(0);
	vector<ll> postsum(N+1), postsum2(N+1);
	for (int i = N; i--;) {
		postsum[i] = a[i] + postsum[i+1];
		postsum2[i] = a[i] * i + postsum2[i+1];
	}
	rep(i,1,N+1) {
		auto eval = [&](int j, int i) -> pair<ll, int> {
			// dp[j] + a[j] * (i - j) + ... + a[i-1] * (i - (i-1))
			return {dp[j].first + (postsum[j] - postsum[i]) * i - (postsum2[j] - postsum2[i]), dp[j].second};
		};
		auto bad = [&](int i, int j, int k) {
			// we may negate everything, disregard tails, and consider
			// -dp[i] + postsum2[i] - postsum[i] * x for i, j, k
			ll ai = -dp[i].first + postsum2[i], ki = -postsum[i];
			ll aj = -dp[j].first + postsum2[j], kj = -postsum[j];
			ll ak = -dp[k].first + postsum2[k], kk = -postsum[k];
			assert(ki < kj && kj < kk);
			// Now we wonder, is j redundant in the sense that i or k is always greater?
			return (ai - aj) * __int128_t(kk - kj) >= (aj - ak) * __int128_t(kj - ki);
			// if answer * sum(a) < 2^63, this wouldn't need 128-bit numbers (happens e.g.
			// when k, a_i < 1000). doubles probably work in practice.
		};
		while (goodj.size() >= 3 && bad(goodj[sz(goodj)-3], goodj[sz(goodj)-2], goodj[sz(goodj)-1])) {
			int j = goodj.back();
			goodj.pop_back();
			goodj.pop_back();
			goodj.push_back(j);
		}
		while (goodj.size() >= 2 && eval(goodj[0], i) >= eval(goodj[1], i)) {
			goodj.pop_front();
		}
		dp[i] = eval(goodj[0], i);
		dp[i].first += resetCost;
		dp[i].second++;
		goodj.push_back(i);
	}
	cout << dp[N].first - resetCost << endl;
	cerr << "cuts: " << dp[N].second - 1 << endl;
	exit(0);
}
