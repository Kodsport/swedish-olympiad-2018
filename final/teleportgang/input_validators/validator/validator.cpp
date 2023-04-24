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
    int n = Int(2, Arg("maxn")); Space();
    int m = Int(0, Arg("maxm")); Endl();

    int s = Int(1, n); Space();
    int t = Int(1, n); Endl();
    assert(s!=t);

    set<set<int>> seen;
    for (int i = 0; i < m; i++)
    {
        int a = Int(1,n); Space();
        int b = Int(1,n); Endl();

        assert(a!=b);
        seen.insert({a,b});
    }

    Eof();
}
