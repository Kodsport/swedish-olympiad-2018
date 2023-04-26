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

template <typename Out> inline void split(const string& s, char delim, Out result) { istringstream iss(s); string item; while (getline(iss, item, delim)) { *result++ = item; } }
inline vector<string> split(const string& s, char delim) { vector<string> elems; split(s, delim, back_inserter(elems)); return elems; }

bool topsort(int u, vi& color, vector<vector<pii>>& edges, vi& order)
{
    if (color[u]==1) return false;
    if (color[u]==2) return true;
    color[u] = 1;

    for(auto e : edges[u])
    {
        if (!topsort(e.first, color, edges, order)) return false;
    }


    order.push_back(u);
    color[u] = 2;
    return true;
}

bool dfs(int u, vi& vis, vector<vector<pii>>& edges)
{
    if (u==vis.size()-1) return 1;
    if (vis[u]) return 0;
    vis[u] = 1;

    for(auto e : edges[u])
    {
        if (dfs(e.first, vis, edges)) return 1;
    }

    return 0;
}

void run() {
    int n = Int(1, Arg("maxn")); Space();
    int m = Int(1, Arg("maxm")); Endl();

    vector<vector<pii>> edges(n);
    vi indeg(n);
    set<pii> edgelist;
    for (int i = 0; i < m; i++)
    {
        int a = Int(1, n); Space();
        int b = Int(a+1, n); Space();
        int w = Int(1, int(2e6)); Endl();
        assert(edgelist.find(pii(a,b))==edgelist.end());
        edgelist.insert(pii(a,b));
        edges[a-1].push_back(pii(b-1, w));
        indeg[b-1]++;
    }
    vi color(n, 0);
    
    vector<int> order;
    rep(i,0,n)
    {
        assert(topsort(i, color, edges, order));
    }

    assert(order.size()==n);


    rep(i,0,n)
    {
        assert(indeg[i]==0);
        for (auto e : edges[i])
        {
            indeg[e.first]--;
        }
    }

    vi vis(n);
    assert(dfs(0,vis,edges));

    Eof();
}
