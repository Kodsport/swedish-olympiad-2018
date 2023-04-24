#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
	}
};

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, M;
	cin >> N >> M;
	vector<tuple<int, int, int, int, int>> eds;
	rep(i,0,M) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		eds.push_back(make_tuple(min(x, y), a, b, x, y));
	}
	sort(all(eds));
	UF uf(N);
	int sumx = 0, sumy = 0;
	vector<pii> used;
	trav(ed, eds) {
		int _, a, b, x, y;
		tie(_, a, b, x, y) = ed;
		if (uf.same_set(a, b)) continue;
		uf.join(a, b);
		sumx += x;
		sumy += y;
		used.emplace_back(a, b);
	}
	cout << sumx << ' ' << sumy << endl;
	trav(e, used) {
		cout << e.first << ' ' << e.second << endl;
	}
	exit(0);
}
