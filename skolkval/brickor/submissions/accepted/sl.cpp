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
	string str;
	cin >> str;
	char zero = 'V', one = 'S';
	string target(sz(str), zero);
	queue<pair<string, int>> q;
	q.push(make_pair(str, 0));
	int res = -1;
	set<string> m;
	while (!q.empty()) {
		string s;
		int dist;
		tie(s, dist) = q.front();
		q.pop();
		if (m.count(s)) continue;
		m.insert(s);
		if (s == target) res = dist;
		rep(i,0,sz(s)-1) {
			string s2 = s, s3 = s2.substr(i, 2);
			s3[0] = (s3[0] == zero ? one : zero);
			s3[1] = (s3[1] == zero ? one : zero);
			s2.erase(s2.begin() + i, s2.begin() + i + 2);
			q.push(make_pair(s2 + s3, dist + 1));
			q.push(make_pair(s3 + s2, dist + 1));
		}
	}
	if (res == -1) {
		cout << "IMPOSSIBLE" << endl;
		return 1;
	}
	cout << res << endl;
}
