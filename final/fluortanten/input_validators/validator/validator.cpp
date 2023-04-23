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
    int N = Int(1, Arg("maxn", 1e6)); Endl();
	string mode = Arg("mode", "none");

    vector<int> ppl = SpacedInts(N, -1000, 1000);
	if (mode=="increasing")
	{
		rep(i,0,N-1) assert(ppl[i]<=ppl[i+1]);
	}
	else if (mode=="decreasing")
	{
		rep(i,0,N-1) assert(ppl[i]>=ppl[i+1]);
	}
	else if (mode=="none")
	{

	}
	else
	{
		assert(0);
	}
}
