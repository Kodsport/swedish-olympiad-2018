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
	vi diffs(N);
	rep(i,0,N) cin >> diffs[i];

	vi table;
	rep(i,0,M) {
		int h, m, s;
		char colon;
		cin >> h >> colon >> m >> colon >> s;
		int t = h * 60*60 + m*60 + s;
		table.push_back(t);
	}

	vi res;
	rep(i,0,M) {
		int st = table[i] - diffs[0];
		if (st < 0) continue;
		if (i > 0 && table[i-1] >= st) continue;
		rep(j,0,N) {
			if (i + j >= M) goto fail;
			int t = table[i + j];
			if (t - st != diffs[j]) goto fail;
		}
		res.push_back(st);
fail:;
	}

	if (res.empty()) {
		cout << "fel" << endl;
		return 0;
	}

	bool first = true;
	sort(all(res));
	trav(t, res) {
		int h = t / 60 / 60;
		t -= h * 60 * 60;
		int m = t / 60;
		t -= m * 60;
		int s = t;
		if (!first) cout << ' ';
		first = false;
		cout << setfill('0') << setw(2) << h << ':';
		cout << setfill('0') << setw(2) << m << ':';
		cout << setfill('0') << setw(2) << s;
	}
	cout << endl;

	exit(0);
}
