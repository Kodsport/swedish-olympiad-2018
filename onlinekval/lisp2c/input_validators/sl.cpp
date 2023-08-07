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
void eatword() {
	int count = 0;
	while ('a' <= input[pos] && input[pos] <= 'z')
		pos++, count++;
	assert(count > 0);
}

void rec() {
	if (input[pos] == '(') {
		pos++;
		eatword();
		while (input[pos] == ' ') {
			pos++;
			rec();
		}
		assert(input[pos] == ')');
		pos++;
	} else {
		eatword();
	}
}

int main() {
	cin.sync_with_stdio(false);
	getline(cin, input);
	assert(cin);
	input += '$';
	assert(input[0] == '(');
	rec();
	assert(pos == sz(input)-1);
	char dummy;
	assert(!cin.get(dummy));
	exit(42);
}
