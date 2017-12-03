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
	vi cat(N), tim(N);
	int tot = 0;
	rep(i,0,N) {
		string str;
		int time;
		cin >> time >> str;
		int cats = 0;
		trav(c, str) cats |= 1 << (c - 'a');
		cat[i] = cats;
		tim[i] = time * 100 + 1;
		tot |= cats;
	}

	vi reach(1 << 10, 1000000);
	reach[0] = 0;
	rep(i,0,N) rep(j,0,1 << 10)
		reach[j | cat[i]] = min(reach[j | cat[i]], reach[j] + tim[i]);
	cout << (reach[tot] / 100) << endl;
	cerr << "min number: " << reach[tot] % 100 << endl;
	exit(0);
}
