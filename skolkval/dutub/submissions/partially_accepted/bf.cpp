#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int allbits = 0, N;
int cost[100], bit[100];
const int inf = 1000000;

// Runs in 6.164s
int rec(int at, int bi) {
	if (at == N) return (bi == allbits ? 0 : inf);
	return min(rec(at+1, bi | bit[at]) + cost[at], rec(at+1, bi));
}

// Runs in 0.009s
int rec2(int at, int bi) {
	if (at == N) return (bi == allbits ? 0 : inf);
	if ((bi | bit[at]) == bi)
		return rec2(at+1, bi);
	return min(rec2(at+1, bi | bit[at]) + cost[at], rec2(at+1, bi));
}

// Runs in 1.578s
int rec3(int at, int bi) {
	if (bi == allbits) return 0;
	if (at == N) return inf;
	return min(rec3(at+1, bi | bit[at]) + cost[at], rec3(at+1, bi));
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	cin >> N;
	rep(i,0,N) {
		string s;
		cin >> cost[i] >> s;
		int bits = 0;
		trav(c, s) bits |= 1 << (c - 'a');
		allbits |= bits;
		bit[i] = bits;
	}
	cout << rec3(0, 0) << endl;
	exit(0);
}
