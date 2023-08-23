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
    int t = Int(0,10); Endl();
    int n = Int(2, 500); Space();
    int m = Int(2, 500); Endl();

    vi rowcnt = SpacedInts(n, 0, m);
    rep(i,0,n)
    {
        string line = Line();
        int cnt = 0;
        rep(j,0,line.size())
        {
            cnt += (line[j]=='x');
        }
        assert(cnt<=rowcnt[i]);
    }

    Eof();
}
