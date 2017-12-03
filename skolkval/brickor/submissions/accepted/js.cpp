#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N;

void print(int x) {
    for (int i = N - 1; i >= 0; --i) {
        cout << "VS"[(x & (1 << i)) >> i];
    }
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

    string S;
    cin >> S;
    N = sz(S);
    int T = 0;
    trav(it, S) T = (T << 1) | (it == 'S');
    queue<int> Q;
    const int INF = 100000;
    vector<int> mv(1 << N, INF);
    mv[T] = 0;
    Q.push(T);
    while (!Q.empty()) {
        int nx = Q.front();
        Q.pop();

        auto add = [&](int w) {
            if (mv[w] == INF) {
                mv[w] = mv[nx] + 1;
                Q.push(w);
            }
            return !w;
        };

        rep(i,0,sz(S) - 1) {
            int rmask = (1 << i) - 1;
            int lmask = ((1 << (N - i - 2)) - 1) << (i + 2);
            int mmask = 3 << i;

            int b = ((nx & mmask) >> i) ^ 3;
            int tw = nx & rmask;
            int tw2 = (nx & lmask) >> (i + 2);

            int t = tw | (tw2 << i);
            
            int A = (t << 2) | b;
            int B = t | (b << (sz(S) - 2));
            if (add(A)) goto done;
            if (add(B)) goto done;
        }
    }
done:;
    cout << mv[0] << endl;
}
