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

    vector<pii> people;
    int hi = int(1e9);
    bool same = Arg("samesmallage", 0);
    if (same) hi = int(3e5);
    rep(i,0,n)
    {
        int a = Int(0, hi); Space();
        int b = Int(a+1, hi); Endl();
        people.emplace_back(a,b);
    }

    if (same)
    {
        rep(i,1,n)
        {
            assert(people[i].second-people[i].first==people[0].second-people[0].first);
        }
    }


    Eof();
}
