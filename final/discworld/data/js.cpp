#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef vector<vector<bool>> Layout;
typedef vector<vector<ll>> Field;
template <class T> struct Point3D {
	typedef Point3D P;
	typedef const P& R;
	T x, y, z;
	explicit Point3D(T x=0, T y=0, T z=0) : x(x), y(y), z(z) {}
	bool operator<(R p) const {
		return tie(x, y, z) < tie(p.x, p.y, p.z); }
	bool operator==(R p) const {
		return tie(x, y, z) == tie(p.x, p.y, p.z); }
	P operator+(R p) const { return P(x+p.x, y+p.y, z+p.z); }
	P operator-(R p) const { return P(x-p.x, y-p.y, z-p.z); }
	P operator*(T d) const { return P(x*d, y*d, z*d); }
	P operator/(T d) const { return P(x/d, y/d, z/d); }
	T dot(R p) const { return x*p.x + y*p.y + z*p.z; }
	P cross(R p) const {
		return P(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
	}
	T dist2() const { return x*x + y*y + z*z; }
	double dist() const { return sqrt((double)dist2()); }
	//Azimuthal angle (longitude) to x-axis in interval [-pi, pi]
	double phi() const { return atan2(y, x); } 
	//Zenith angle (latitude) to the z-axis in interval [0, pi]
	double theta() const { return atan2(sqrt(x*x+y*y),z); }
	P unit() const { return *this/(T)dist(); } //makes dist()=1
	//returns unit vector normal to *this and p
	P normal(P p) const { return cross(p).unit(); }
	//returns point rotated 'angle' radians ccw around axis
	P rotate(double angle, P axis) const {
		double s = sin(angle), c = cos(angle); P u = axis.unit();
		return u*dot(u)*(1-c) + (*this)*c - cross(u)*s;
	}
};

template <class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};

bool inside(int r, int c, int N) {
    r -= N / 2;
    c -= N / 2;

    int R = N / 2;
    return r * r + c * c <= R * R;
}

Layout layout(int N) {
    assert(N%2 == 1);
    Layout res(N, vector<bool>(N));
    rep(i,0,N) {
        rep(j,0,N) {
            res[i][j] = inside(i, j, N);
        }
    }
    return res;
}

double nd() {
    return rand() / (RAND_MAX + 0.0) * 2;
}

Field costs(const Layout& layout, bool noise) {
    int N = sz(layout);

    int thecost = 100 * N;
    assert(N%2 == 1);
    Field res(N, vector<ll>(N));
    rep(i,0,N) {
        int has = count(all(layout[i]), 1);
        int percost = thecost / has; 
        int extras = thecost - percost * has;

        rep(j,0,N) {
            int nadd = thecost / has * nd();
            if (layout[i][j]) res[i][j] = percost + (nadd + log(abs(i - N/2) + 1)) * noise;
        }
        rep(j,0,extras) {
            int w = rand() % N;
            if (layout[i][w]) res[i][w]++;
            else --j;
        }
        

    }
    rep(i,0,N) rep(j,0,N) if (layout[i][j]) assert(res[i][j] > 0); else res[i][j] = -1;
    return res;
}

typedef Point3D<double> P3;
typedef Point<double> P;

Field magic(const Layout& layout) {
    int N = sz(layout);
    const int INF = 1e9;
    Field res(N, vector<ll>(N, INF));
    rep(it,0,30000) {
        double R = nd() * 2 * M_PI;
        vector<pair<int, int>> pts;
        rep(it2,0,10000) {
            P3 w = P3(0, -1, 0).rotate(it2 / 10000.0 * M_PI, P3(0, 0, 1).rotate(R, P3(0, -1, 0)));
            P proj = P((1 + w.y)*(N/2), (1 + w.x)*(N/2));
            pts.emplace_back((int)round(proj.x), (int)round(proj.y));

        }
        sort(all(pts));
        pts.erase(unique(all(pts)), pts.end());
        vector<pair<int, int>> npts;
        trav(it, pts) {
            if (it.first >= 0 && it.first < N && it.second >= 0 && it.second < N) {
                if (layout[it.first][it.second]) {
                    npts.push_back(it);
                }
            }
        }
        ll tlen = sz(pts);
        trav(it, npts) res[it.first][it.second] = min(res[it.first][it.second], tlen);
    }

    rep(i,0,N) rep(j,0,N) if (layout[i][j]) assert(res[i][j] != INF); else res[i][j] = -1;
    rep(i,0,N) rep(j,0,N) if (layout[i][j]) res[i][j] = N * N / res[i][j];
    return res;
}

void dump(int T, int K, const Field& m, const Field& c) {
    cout << T << endl;
    int N = sz(m);
    cout << N << " " << K << endl;
    rep(i,0,N) {
        rep(j,0,N) {
            if (j) cout << " ";
            cout << m[i][j];
        }
        cout << endl;
    }
    rep(i,0,N) {
        rep(j,0,N) {
            if (j) cout << " ";
            cout << c[i][j];
        }
        cout << endl;
    }

}

void c1() {
    int N = 999;
    Layout l = layout(N);
    Field c = costs(l, false);
    Field m = magic(l);

    dump(1, 1000000000, m, c);
}

void c2() {
    int N = 999;
    Layout l = layout(N);
    Field c = costs(l, false);
    rep(i,0,N) rep(j,0,N) if (c[i][j] > 0) c[i][j] = rand() % 1000 + 1000;
    Field m = magic(l);

    dump(2, 1000000000, m, c);
}

void c3() {
    int N = 999;
    Layout l = layout(N);
    Field c = costs(l, true);
    Field m = magic(l);

    dump(3, 1000000000, m, c);
}

void addBump(Field& f, int cx, int cy) {
    int N = sz(f);
    int bz = rand() % 1000;
    rep(i,cx-25,cx+26)
    rep(j,cy-25,cy+26) {
    
        int mx = 25 * 25;
        if (i >= 0 && j >= 0 && i < N && j < N) {
            if (f[i][j] == -1) continue;

            int dx = abs(i - cx),
                dy = abs(j - cy);

            int tr = dx * dx + dy * dy;

            double w = (tr + 0.0) / mx;
            f[i][j] += bz * w;

        }

    }
}

void c4() {
    int N = 999;
    Layout l = layout(N);
    Field c = costs(l, true);
    Field m = magic(l);

    rep(i,0,1000) {
        addBump(m, rand()%N, rand()%N);
    }

    dump(4, 1000000000, m, c);
}

void c5() {
    int N = 999;
    Layout l = layout(N);
    Field c = costs(l, true);
    Field m = magic(l);

    rep(i,0,25) {
        addBump(c, rand()%N, rand()%N);
    }

    dump(5, 1000000000, m, c);
}

int main(int argc, char** argv) {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

    int N = atoi(argv[1]);
    srand(N);
    if (N == 1) c1();
    if (N == 2) c2();
    if (N == 3) c3();
    if (N == 4) c4();
    if (N == 5) c5();
}
