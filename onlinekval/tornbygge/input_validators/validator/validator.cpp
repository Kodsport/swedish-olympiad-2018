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
    int n = Int(1, Arg("maxn", int(1e5))); Endl();
    vi ws;
    int maxh = Arg("maxh", int(1e9));
    rep(i,0,n)
    {
        int w = Int(1, int(1e9)); Space();
        int h = Int(1, maxh); Endl();
        ws.push_back(w);
    }
    if (Arg("wdecr",0))
    {
        rep(i,0,n)
        {
            assert(ws[i]==n-i);
        }
    }

    Eof();
}
