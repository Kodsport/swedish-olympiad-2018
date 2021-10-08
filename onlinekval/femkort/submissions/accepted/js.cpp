#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

    vector<map<char, set<int>>> left(2);
    vector<vector<pair<char, int>>> cards(2, vector<pair<char, int>>(5));
    rep(i,0,2) {
        rep(j,0,5) {
            char s;
            int v;
            cin >> s >> v;
            left[i][s].insert(v);
            cards[i][j] = make_pair(s, v);
        }
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
    cout << char('A' + turn) << endl;
    if (cheat[0] && cheat[1]) cout << "A och B fuskar" << endl;
    else if (cheat[0]) cout << "A fuskar" << endl;
    else if (cheat[1]) cout << "B fuskar" << endl;
}
