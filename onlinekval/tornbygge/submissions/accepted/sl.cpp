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
	vector<pii> bricks;
	rep(i,0,N) {
		int w, h;
		cin >> w >> h;
		bricks.emplace_back(w, h);
	}
	sort(all(bricks));
	// width strictly increasing, height weakly decreasing
	map<int, ll> answers;
	answers[INT_MAX] = 0;
	pii lastbr = {-1, -1};
	trav(br, bricks) {
		if (br == lastbr) continue;
		lastbr = br;
		int h = br.second;
		auto it = answers.lower_bound(h);
		assert(it != answers.end());
		ll nh = it->second + h;
		if (it->first == h) {
			it->second = nh;
		} else {
			it = answers.insert(it, make_pair(h, nh));
		}
		while (it != answers.begin()) {
			--it;
			if (it->second <= nh) it = answers.erase(it);
			else break;
		}
	}

	ll res = 0;
	trav(pa, answers) res = max(res, pa.second);
	cout << res << endl;

	exit(0);
}
