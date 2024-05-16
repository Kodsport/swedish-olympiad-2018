#include "validator.h"

void run() {
	int n = Int(1, Arg("maxn")); Endl();
	int maxc = Arg("maxcat");
	for (int i = 0; i < n; i++) {
        Int(1, 900); Space();
        string s = Line();
        assert(1 <= s.size() && s.size() <= maxc);
        assert(set<char>(s.begin(), s.end()).size() == s.size());
        for (char c : s) {
            assert('a' <= c && c <= 'j');
        }
	}
}
