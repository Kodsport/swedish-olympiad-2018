#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> nodes(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i];
    }
    while(q--) {
        vector<vector<bool>> possible(n+1, vector<bool>(m, false));
        int a, b;
        cin >> a >> b;
        for (int i = 0; i < m; i++)
            possible[a][i] = true;
        for (int i = a+1; i <= b; i++) {
            for (int j = 0; j < m; j++) {
                if (!possible[i-1][j])
                    continue;
                if (nodes[i] < nodes[i-1]) {
                    for (int k = 0; k < j; k++) {
                        possible[i][k] = true;
                    }
                }
                else if (nodes[i] > nodes[i-1]) {
                    for (int k = j+1; k < m; k++) {
                        possible[i][k] = true;
                    }
                }
                else {
                    possible[i][j] = true;
                }
            }
        }
        bool ans = false;
        for (int j = 0; j < m; j++) {
            if (possible[b][j])
                ans = true;
        }
        if (ans)
            cout << "Ja" << endl;
        else
            cout << "Nej" << endl;
    }
}
