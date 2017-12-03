#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool ok(int ans, vi nres, vi res) {
    nres[0] += ans;
    rep(i,0,sz(nres) - 1) {
        if (i != sz(nres) - 2) {
            int cmove = (nres[i] - nres[i + 1]) / 2;
            int move = max(0, cmove);
            nres[i] -= move;
            nres[i + 1] += move;
        }
        if (nres[i] < nres[i + 1]) return false;
    }
    return true;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

    int N;
    cin >> N;
    vi res;
    rep(i,0,N) {
        int x;
        cin >> x;
        res.push_back(x);
    }
    int lo = -1;
    int hi = 1;
    while (!ok(hi, res, res)) hi *= 2;
    while (hi - lo > 1) {
        int ans = (lo + hi) / 2;
        if (ok(ans, res, res)) hi = ans;
        else lo = ans;
    }
    cout << hi << endl;
}
