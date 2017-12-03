#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string input;
int pos = 0;
void rec() {
	if (input[pos] == '(') {
		pos++;
		while (isalpha(input[pos])) {
			cout.put(input[pos]);
			pos++;
		}
		cout.put('(');
		bool first = true;
		while (input[pos] != ')') {
			assert(input[pos] == ' ');
			pos++;
			if (!first) cout.put(','), cout.put(' ');
			first = false;
			rec();
		}
		cout.put(')');
		pos++;
	} else {
		while (isalpha(input[pos])) {
			cout.put(input[pos]);
			pos++;
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	getline(cin, input);
	input += ' ';
	rec();
	endl(cout);
	assert(pos == sz(input)-1);
	exit(0);
}
