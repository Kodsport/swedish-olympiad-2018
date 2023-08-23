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
	set<char> chars;
	string s = Line(); Eof();
	int maxn = Arg("maxn");
    assert(s.size()<=maxn);
	assert(s.size()>=4);
	trav(c, s)
	{
		chars.insert(c);
		
	}

	int maxk = Arg("maxk", -1);
	if (maxk != -1) assert(chars.size() <= maxk);
	int k_equals = Arg("k_equals", -1);
	if (k_equals != -1) assert(chars.size() == k_equals);
	auto it = chars.begin();

	while (it!=chars.end() && next(it)!=chars.end())
	{
		assert(*it+1==*next(it));
		it = next(it);
	}
}
