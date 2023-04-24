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

template <typename Out> inline void split(const string& s, char delim, Out result) { istringstream iss(s); string item; while (getline(iss, item, delim)) { *result++ = item; } }
inline vector<string> split(const string& s, char delim) { vector<string> elems; split(s, delim, back_inserter(elems)); return elems; }

inline int sToi(string& time)
{
    vector<string> sp = split(time, ':');

    int t = 0;

    t += stoi(sp[0]) * 3600;
    t += stoi(sp[1]) * 60;
    t += stoi(sp[2]);

    return t;
}

void run() {
    int n = Int(1, Arg("maxn", int(1e6))); Space();
    int neq = Arg("n_equals",-1);
    if (neq!=-1) assert(n==neq);
    int m = Int(1, Arg("maxm", 3000)); Endl();
    
    vector<int> coming = SpacedInts(n, 0, int(1e9));
    assert((set<int>(all(coming))).size()==coming.size());

    for (int i = 0; i < n-1; i++) assert(coming[i]<coming[i+1]);

    set<int> seen;
    int prev = -1;
    for (int i = 0; i < m; i++)
    {
        string time = Line();
        int t = sToi(time);
        assert(t>prev);
        prev=t;
        seen.insert(t);
    }
    assert(seen.size()==m);

    Eof();
}
