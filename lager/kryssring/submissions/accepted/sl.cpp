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
	cin >> N >> N >> M;
	vi cr(N);
	rep(i,0,N) cin >> cr[i];
	vector<string> board(N);
	rep(i,0,N) cin >> board[i];
	int sc = 0;
	rep(i,0,N) {
		int remx = cr[i], remo = M - remx;
		rep(j,0,M)
			remx -= board[i][j] == 'x',
			remo -= board[i][j] == 'o';
		rep(j,0,M) {
			if (board[i][j] != '.') continue;
			int wx = 0, wo = 0;
			if (i >= 2 && board[i-1][j] == board[i-2][j]) {
				if (board[i-1][j] == 'o') wo++;
				if (board[i-1][j] == 'x') wx++;
			}
			if (j >= 2 && board[i][j-1] == board[i][j-2]) {
				if (board[i][j-1] == 'o') wo++;
				if (board[i][j-1] == 'x') wx++;
			}
			if (j >= 2 && i >= 2 && board[i-1][j-1] == board[i-2][j-2]) {
				if (board[i-1][j-1] == 'o') wo++;
				if (board[i-1][j-1] == 'x') wx++;
			}
			if (j + 2 < M && i >= 2 && board[i-1][j+1] == board[i-2][j+2]) {
				if (board[i-1][j+1] == 'o') wo++;
				if (board[i-1][j+1] == 'x') wx++;
			}
			if ((wo > wx && remx) || !remo) board[i][j] = 'x', remx--;
			else board[i][j] = 'o', remo--;
		}
		rep(j,0,M) {
			int wx = 0, wo = 0;
			if (i >= 2 && board[i-1][j] == board[i-2][j]) {
				if (board[i-1][j] == 'o') wo++;
				if (board[i-1][j] == 'x') wx++;
			}
			if (j >= 2 && board[i][j-1] == board[i][j-2]) {
				if (board[i][j-1] == 'o') wo++;
				if (board[i][j-1] == 'x') wx++;
			}
			if (j >= 2 && i >= 2 && board[i-1][j-1] == board[i-2][j-2]) {
				if (board[i-1][j-1] == 'o') wo++;
				if (board[i-1][j-1] == 'x') wx++;
			}
			if (j + 2 < M && i >= 2 && board[i-1][j+1] == board[i-2][j+2]) {
				if (board[i-1][j+1] == 'o') wo++;
				if (board[i-1][j+1] == 'x') wx++;
			}
			if (board[i][j] == 'x') sc += wx;
			else sc += wo;
		}
		cout << board[i] << endl;
	}
	cerr << "score = " << sc << endl;
	exit(0);
}
