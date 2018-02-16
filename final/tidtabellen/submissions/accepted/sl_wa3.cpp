#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int day = 24*60*60;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, M;
	cin >> N >> M;
	vi diffs(N);
	rep(i,0,N) cin >> diffs[i];
	int prunei = -1;
	rep(i,1,N) if (diffs[i] - diffs[0] >= day) {
		prunei = i;
		break;
	}
	if (prunei != -1) {
		rep(i,0,N) {
			if (i + prunei >= N) break;
			if (diffs[i + prunei] - diffs[i] != day) {
				cout << "fel" << endl;
				return 0;
			}
		}
		diffs.erase(diffs.begin() + prunei, diffs.end());
		N = sz(diffs);
	}
	if (N > M) {
		cout << "fel" << endl;
		return 0;
	}

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
		int prevtime = (i > 0 ? table[i-1] : table.back() - day);
		if (prevtime >= st) continue;
		rep(j,0,N) {
			int t = table[(i + j) % M] + day * ((i + j) / M);
			if (t - st != diffs[j]) goto fail;
		}
		st %= day;
		if (st < 0) st += day;
		res.push_back(st);
fail:;
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
