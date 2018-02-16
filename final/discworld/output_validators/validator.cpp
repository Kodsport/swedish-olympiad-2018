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

ll INF = 1e15;
long long compute(const vector<vi>& M) {
    // convention: x = r, y = c, arrays indexed as ar[x][y]
    int N = sz(M);

    vector<vector<ll>> res(N, vector<ll>(N, INF));
    set<pair<ll, pii>> Q;
    Q.emplace(M[0][N/2], pii(0, N/2));
    res[0][N/2] = M[0][N/2];
    
    while (!Q.empty()) {
        ll t;
        pii cur;
        tie(t, cur) = *Q.begin(); Q.erase(Q.begin());
        // cout << cur.first << " " << cur.second << " " << t << endl;
        rep(dx,-1,2) rep(dy,-1,2) {
            if (abs(dx) + abs(dy) != 1) continue;

            int nx = cur.first + dx,
                ny = cur.second + dy;
            if (nx >= 0 && ny >= 0 && nx < N && ny < N && M[nx][ny] != -1) {
                // cout << "going to " << nx << " " << ny << endl;
                ll nt = t + M[nx][ny];
                if (nt < res[nx][ny]) {
                    if (res[nx][ny] != INF) Q.erase(make_pair(res[nx][ny], pii(nx, ny)));
                    Q.emplace(nt, pii(nx, ny));
                    // cout << "pushing " << nx << " " << ny << endl;
                    res[nx][ny] = nt;
                }
            }
        }
    }

    return res[N-1][N/2];
}

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

    int N, K;
    fin >> N >> K;

    vector<vi> M(N, vi(N));
    rep(i,0,N) rep(j,0,N) fin >> M[i][j];

    vector<vi> P(N, vi(N));
    rep(i,0,N) rep(j,0,N) fin >> P[i][j];
    assert_done(fin);
    fin.close();

    // cout << "read input" << endl;
    long long bestAnswer;
    fin.open(answer_file);
    fin >> bestAnswer;
    assert_done(fin);
    fin.close();

    try {
        cin.exceptions(cin.failbit | cin.badbit | cin.eofbit);
        vector<vi> I(N, vi(N));
        rep(i,0,N) rep(j,0,N) cin >> I[i][j];
        assert_done(cin);

        long long use = 0;
        rep(i,0,N) rep(j,0,N) {
            if (M[i][j] == -1 && I[i][j] > 0) die("Using magic on non-existing square");
            if (I[i][j] < 0) die("Using negative magic");
            if (I[i][j] % P[i][j]) die("Non-integer magic increase");
            use += I[i][j];
            if (use > K) die("Too many spells");
        }

        long long withoutRes = compute(M);
        rep(i,0,N) rep(j,0,N) M[i][j] += I[i][j] / P[i][j];
        long long withRes = compute(M);

        bestAnswer -= withoutRes;
        withRes -= withoutRes;

        assert(bestAnswer > 0);
        assert(withRes >= 0);

        accept(20.0 * withRes / bestAnswer);
    } catch(...) {
        die("IO failure");
    }
}
