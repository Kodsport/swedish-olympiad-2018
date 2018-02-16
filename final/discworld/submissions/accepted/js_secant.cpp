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

    int T, N, M;
    cin >> T >> N >> M;
    vector<vi> V(N, vi(N));
    rep(i,0,N) rep(j,0,N) cin >> V[i][j];
    rep(i,0,N) rep(j,0,N) cin >> V[i][j];

    ll bestcost = V[0][N/2];
    int w = 0;
    rep(i,0,N) {
        ll s = 0;
        rep(j,0,N) {
            if (V[i][j] > 0) s += V[i][j];
        }
        if (s < bestcost) {
            bestcost = s;
            w = i;
        }
    }

    vector<vi> A(N, vi(N));
    ll X = M / bestcost * bestcost;
    rep(i,0,N) if (V[w][i] > 0) A[w][i] += X;

    rep(i,0,N) {
        rep(j,0,N) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
