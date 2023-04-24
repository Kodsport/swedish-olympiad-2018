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
    int M = Int(30, 200); Space();
    int S = Int(1, M); Space();
    int G = Int(S, M); Endl();

    double A = Float(0.1, 1.0); Space();
    double B = Float(0.1, 1.0); Endl();

    int L = Int(0, 100); Space();
    int R = Int(0, 100); Endl();

    if (Arg("sgeq",0))
    {
        assert(S==G);
    }
    if (Arg("lr0",0))
    {
        assert(L==0 && R==0);
    }

    Eof();
}
