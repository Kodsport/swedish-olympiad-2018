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
	int N, M;
	cin >> N >> M;
	assert(N <= 10);
	assert(M <= 20);
	vector<vector<pair<int, double>>> gr(N);
	double maxw = 0;
	rep(i,0,M) {
		int a, b;
		double w;
		cin >> a >> b >> w;
		--a, --b;
		assert(0 <= a && a < b && b < N);
		assert(w > 0);
		maxw = max(maxw, w);
		gr[a].emplace_back(b, w);
	}
	int len = -1;
	auto works = [&](double base) {
		double inf = numeric_limits<double>::max();
		vector<pair<double, int>> best(N, {-inf, 0});
		best[0] = {0.0, 0};
		rep(i,0,N) trav(e, gr[i])
			best[e.first] = max(best[e.first], {e.second - base + best[i].first, best[i].second+1});
		len = best[N-1].second;
		return best[N-1].first >= 0;
	};
	if (!works(0)) {
		// No path!
		cerr << "IMPOSSIBLE" << endl;
		return 1;
	}
	double lo = 0, hi = maxw;
	rep(it,0,100) {
		double mid = (lo + hi) / 2;
		if (works(mid)) lo = mid;
		else hi = mid;
	}
	bool r = works(lo);
	assert(r);
	cout << setprecision(10) << fixed << (lo + hi) / 2 << endl;
	cerr << "length = " << len << endl;
	exit(0);
}
