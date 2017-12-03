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

    int N;
    cin >> N;
    vector<pii> V(N);
    int C = 0;
    rep(i,0,N) {
        int T, B = 0;
        cin >> T;
        string x;
        cin >> x;
        trav(it, x) B = B | (1 << (it - 'a'));
        V.emplace_back(T, B);
        C |= B;
    }
    vi res(1 << 10, 1000 * 10);
    res[0] = 0;
    rep(i,1,sz(res)) {
        trav(it, V) {
            res[i] = min(res[i], res[i & ~it.second] + it.first);
        }
    }
    cout << res[C] << endl;
}
