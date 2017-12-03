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
	vector<tuple<ll, ll, int>> v(N);
	rep(i,0,N) {
		ll birth, death;
		cin >> birth >> death;
		v[i] = make_tuple(birth, death, i);
	}
	sort(all(v));

	ll lastdeath = 0;
	vector<ll> res(N);
	trav(pa, v) {
		ll birth, death;
		int i;
		tie(birth, death, i) = pa;
		if (death > lastdeath) {
			res[i] = death - max(lastdeath, birth);
			lastdeath = death;
		}
	}

	trav(x, res) cout << x << '\n';
	exit(0);
}
