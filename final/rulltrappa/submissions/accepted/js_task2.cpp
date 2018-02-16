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

    int M, S, G;
    cin >> M >> S >> G;

    double A, B;
    cin >> A >> B;
    double L, R;
    cin >> L >> R;

    double stand = M / S;
    double walk = M / G;

    cerr << stand << " " << walk << endl;

    if (stand < walk) cout << "latmask" << endl;
    else cout << "friskus" << endl;
}
