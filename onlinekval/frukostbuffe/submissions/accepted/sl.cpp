#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N;
vi solve(vi a) {
	int best = 0;
	vi res(N);
	rep(i,0,N) {
		res[i] = a[i] + best;
		best = max(a[i] + best, 0);
	}
	return res;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	cin >> N;
	vi a(N);
	rep(i,0,N) cin >> a[i];
	vi sol = solve(a);
	reverse(all(a));
	vi solr = solve(a);
	reverse(all(a));
	reverse(all(solr));
	int res = INT_MIN;
	rep(i,0,N) {
		res = max(res, min(sol[i], solr[i]));
	}
	cout << res << endl;

	exit(0);
}
