#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void run() {
    int n = Int(1, Arg("maxn", int(1e5))); Space();
    int m = Int(1, Arg("maxm", int(1e5))); Space();
    int q = Int(1, Arg("maxq", int(1e5))); Endl();

    vi nums = SpacedInts(n, 1, int(1e9));
    for (int i = 0; i < q; i++)
    {
        int a = Int(1, n); Space();
        int b = Int(a, n); Endl();
    }

    Eof();
}
