#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;

ll n,m,k,T;

vector<vi> C(100001, vi());
int dist[100001] = {0};
bool mark[100001] = {0};
vector<ll> ind;

bool comp(int i, int j){
    return dist[i] > dist[j];
}

ll lim = 30000;
ld ans;

ld test(ll i, ll j){
    ll sum = 0;
    for(int c1 = 0; c1 < lim; c1++){
        int a = i;
        while(a != j){
            if(!mark[a]){
                sum += dist[a];
                break;
            }
            else{
                a = rand()%n;
                sum++;
            }
        }
        //if(c1 > 30 && ld(sum)/ld(c1) > 2.0*ans)return big;
    }
    return ld(sum)/ld(lim);
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> m;
    assert(n <= 10 && m <= 20);
    cin >> c >> d;
    c--;
    d--;
   // lim = 40000000/n;
    for(int c1 = 0; c1 < m; c1++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    for(int c1 = 0; c1 < n; c1++){
        dist[c1] = big;
        ind.push_back(c1);
    }

    queue<int> Q;
    Q.push(d);
    dist[d] = 0;

    while(!Q.empty()){
        a = Q.front();
        Q.pop();
        for(int c1 = 0 ;c1 < sz(C[a]); c1++){
            b = C[a][c1];
            if(dist[b] == big){
                dist[b] = dist[a]+1;
                Q.push(b);
            }
        }
    }
    sort(all(ind),comp);
    ans = dist[c];

    for(int c1 = 0; c1 <= n; c1++){
        ans = min(ans, test(c,d));
        if(c1 == n)break;
        mark[ind[c1]] = 1;
    }
    cout << setprecision(18) << ans << "\n";
    return 0;
}

