#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = d;
    ans += c;
    a = max(0, a - c);
    ans += b / 2;
    b %= 2;
    ans += b;
    a = max(0, a - 2 * b);
    ans += (a + 3) / 4;
    cout << ans << endl;
}
