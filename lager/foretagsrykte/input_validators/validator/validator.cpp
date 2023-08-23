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
    int n = Int(2, Arg("maxn", int(4e5))); Space();
    int k = Int(0, Arg("maxk", int(2e9))); Endl();

    vi nums = SpacedInts(n, 1, (int)Arg("maxr", int(1e7)));
    if (Arg("samer", 0))
    {
        for (int i=0;i<n-1;i++) assert(nums[i]==nums[i+1]);
    }

    Eof();
}
