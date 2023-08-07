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


#define alfN 0
#define betN 1




void run() {
    vector<map<char, set<int>>> left(2);
    vector<vector<pair<char, int>>> cards(2, vector<pair<char, int>>(5));
    rep(i,0,2) {
        rep(j,0,5) {
            char s = Char(); Space();
            
            int v = Int(2,14); Endl();
            left[i][s].insert(v);
            cards[i][j] = make_pair(s, v);
        }
    }

    if (Arg("same", 0))
    {
        assert(cards[0][0].first==cards[1][0].first);
        rep(i,0,4) assert(cards[0][i].first==cards[0][i+1].first);
        rep(i,0,4) assert(cards[1][i].first==cards[1][i+1].first);
    }

    vector<bool> cheat(2);
    bool turn = 0;
    rep(i,0,5) {
        rep(j,0,2) {
            left[j][cards[j][i].first].erase(cards[j][i].second);
        }
        if (cards[0][i].first != cards[1][i].first) {
            cheat[!turn] = cheat[!turn] | !left[!turn][cards[turn][i].first].empty();
        } else {
            turn = cards[0][i].second < cards[1][i].second;
        }
    }

    if (Arg("nocheat", 0))
    {
        assert(!cheat[0]);
        assert(!cheat[1]);
    }


    Eof();
}
