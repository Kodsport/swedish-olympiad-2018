// usage: ./a.out input_file correct_output output_dir < contestants_output

#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

string input_file, output_dir, answer_file;

void die(const string& msg) {
    cout << msg << endl;
    ofstream(output_dir + "/score.txt") << 0;
    exit(43);
}

void accept(double score) {
    ofstream(output_dir + "/score.txt") << setprecision(2) << fixed << score;
    exit(42);
}

void assert_done(istream& is) {
    try {
        string dummy;
        is >> dummy;
        die("extraneous data: " + dummy);
    } catch(...) {}
}

int bestScores[] = {
// submission 2600786
30,
1521,
1753,

// submission 2601002
3553,
93397,
143308,
53378,
155212,
63599,

// submission 2600960
87874
};

int main(int argc, char** argv) {
    if (argc < 4) exit(1);
    cin.sync_with_stdio(0);
    cin.tie(0);

    input_file = argv[1];
    answer_file = argv[2];
    output_dir = argv[3];

    ifstream fin(input_file);
    fin.exceptions(cin.failbit | cin.badbit | cin.eofbit);

    int T;
    fin >> T;
    if (T == 0) accept(0);

    int N, M;
    fin >> N >> M;

	vi crosses(N);
	rep(i,0,N) fin >> crosses[i];

	vector<string> ingrid(N);
	rep(i,0,N) fin >> ingrid[i];
    assert_done(fin);
    fin.close();

	auto solve = [&](istream& is) -> ll {
		string line;
		vector<string> grid(N);
		rep(i,0,N) {
			getline(is, line);
			if (sz(line) != M) die("wrong size of line");
			int cr = 0;
			rep(j,0,M) {
				if (line[j] == 'x') cr++;
				else if (line[j] == 'o') ;
				else die("invalid character");
				if (ingrid[i][j] != '.' && ingrid[i][j] != line[j]) die("overwrite");
			}
                        if(cr != crosses[i]) die("wrong number");
			grid[i] = line;
		}
		ll w = 0;
		rep(i,0,N) rep(j,0,M) {
			char ch = grid[i][j];
			if (j >= 2 && ch == grid[i][j-1] && ch == grid[i][j-2])
				w++;
			if (i >= 2 && ch == grid[i-1][j] && ch == grid[i-2][j])
				w++;
			if (i >= 2 && j >= 2 && ch == grid[i-1][j-1] && ch == grid[i-2][j-2])
				w++;
			if (i >= 2 && j+2 < M && ch == grid[i-1][j+1] && ch == grid[i-2][j+2])
				w++;
		}
		return w;
	};

    // fin.open(answer_file);
	ll best = bestScores[T - 1];
	ll secondBest = best;
	assert(secondBest >= best);
    // assert_done(fin);
    // fin.close();

    try {
        cin.exceptions(cin.failbit | cin.badbit | cin.eofbit);
		ll cost = solve(cin);
        assert_done(cin);

		if (cost >= 2*secondBest) accept(0);
		else {
			double r = (cost - best) / (double)(2 * secondBest - best);
			assert(r <= 1);
			double score = min(10.0, 10 * (1-r));
			accept(score);
		}
    } catch(...) {
        die("IO failure");
    }
}
