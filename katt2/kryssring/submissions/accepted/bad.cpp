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
	int T, N, M;
	cin >> T >> N >> M;
	vi w(N);
	rep(i,0,N) cin >> w[i];
	vector<string> board(N);
	rep(i,0,N) cin >> board[i];
	rep(i,0,N) {
		int x = 0;
		rep(j,0,M) {
			if (board[i][j] == 'x') x++;
		}
		int rem = w[i] - x;
		rep(j,0,M) {
			if (board[i][j] == '.') {
				if (rem) {
					board[i][j] = 'x';
					rem--;
				} else {
					board[i][j] = 'o';
				}
			}
		}
		cout << board[i] << endl;
	}
	exit(0);
}
