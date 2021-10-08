// usage: ./a.out input_file correct_output < contestants_output

#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

string input_file, answer_file;

void die(const string& msg) {
    cout << msg << endl;
    exit(43);
}

void accept() {
    exit(42);
}

void assert_done(istream& is) {
    try {
        string dummy;
        is >> dummy;
        die("extraneous data: " + dummy);
    } catch(...) {}
}

struct UF {
	vi v;
	UF(int n) : v(n, -1) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (-v[a] < -v[b]) swap(a, b);
		v[a] += v[b];
		v[b] = a;
		return true;
	}
};

int main(int argc, char** argv) {
    if (argc < 4) exit(1);
    cin.sync_with_stdio(0);
    cin.tie(0);

    input_file = argv[1];
    answer_file = argv[2];

    ifstream fin(input_file);
    fin.exceptions(cin.failbit | cin.badbit | cin.eofbit);

    int N, M;
    fin >> N >> M;

	map<pii, pii> eds;
	rep(i,0,M) {
		int a, b, t, c;
		fin >> a >> b >> t >> c;
		assert(t > 0);
		assert(c > 0);
		eds[pii(a, b)] = pii(t, c);
	}

    assert_done(fin);
    fin.close();

    ll bestt, bestc;
    fin.open(answer_file);
    fin >> bestt >> bestc;
    fin.close();

    try {
        cin.exceptions(cin.failbit | cin.badbit | cin.eofbit);
		ll sumt, sumc;
		cin >> sumt >> sumc;

		ll actualSumt = 0, actualSumc = 0;
		bool fail = false;
		UF uf(N);
		rep(i,0,N-1) {
			int a, b;
			cin >> a >> b;
			auto ed = eds[pii(a, b)];
			if (!ed.first || !ed.second) die("Using non-existent edge");
			actualSumt += ed.first;
			actualSumc += ed.second;
			if (!uf.join(a, b)) fail = true;
		}
		if (fail) die("Not a tree");

		if (actualSumt != sumt || actualSumc != sumc) die("Wrong sums");

		if (sumt * sumc > bestt * bestc) die("suboptimal solution");

		// Judge Error if better solution than judge's.
		assert(sumt * sumc == bestt * bestc);

        accept();
    } catch(...) {
        die("IO failure");
    }
}
