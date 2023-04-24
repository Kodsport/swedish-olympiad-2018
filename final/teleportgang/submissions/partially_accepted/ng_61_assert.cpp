#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000000;

int main() {
    int n,m,s,t;
    vector<vector<int> > C(100001, vector<int>());
    int dist[100001];
    cin >> n >> m;
    cin >> s >> t;
	assert(n <= 200 && m <= 400);
    s--;
    t--;
    for(int c1 = 0; c1 < n; c1++){
        dist[c1] = inf;
    }
    for(int c1 = 0; c1 < m; c1++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    queue<int> Q;
    Q.push(t);
    dist[t] = 0;
    double sumdist = 0;
    int nodes = 0;
    double ans = inf;
    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        sumdist += dist[node];
        nodes++;
        ans = min(ans, double(sumdist+n)/double(nodes));
        for(int c1 = 0; c1 < C[node].size(); c1++){
            int node2 = C[node][c1];
            if(dist[node2] == inf){
                dist[node2] = dist[node]+1;
                Q.push(node2);
            }
        }
    }
    ans = min(ans, double(dist[s]));
    cout << setprecision(18) << ans << "\n";
    return 0;
}

