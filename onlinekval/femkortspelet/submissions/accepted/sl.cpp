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
	vector<char> asuite(5), bsuite(5);
	vi anum(5), bnum(5);
	rep(i,0,5) cin >> asuite[i] >> anum[i];
	rep(i,0,5) cin >> bsuite[i] >> bnum[i];
	bool a = true, acheat = false, bcheat = false;
	rep(i,0,5) {
		if (asuite[i] == bsuite[i]) {
			// bool olda = a;
			a = (anum[i] > bnum[i]);
			/* if (olda == a) { // wikipedia's rules
				rep(j,i+1,5) {
					if ( a && asuite[i] == bsuite[j] && anum[i] < bnum[j]) bcheat = true;
					if (!a && bsuite[i] == asuite[j] && bnum[i] < anum[j]) acheat = true;
				}
			} */
		} else {
			rep(j,i+1,5) {
				if ( a && asuite[i] == bsuite[j]) bcheat = true;
				if (!a && bsuite[i] == asuite[j]) acheat = true;
			}
		}
	}
	cout << (a ? 'A' : 'B') << endl;
	if (acheat && bcheat) cout << "A och B fuskar" << endl;
	else if (acheat) cout << "A fuskar" << endl;
	else if (bcheat) cout << "B fuskar" << endl;
	exit(0);
}
