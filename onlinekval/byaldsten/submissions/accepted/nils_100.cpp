#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int> > FI(n);
    vector<int> D(n);
    vector<int> ANS(n);
    for(int c1 = 0; c1 < n; c1++){
        cin >> FI[c1].first >> D[c1];
        FI[c1].second = c1;
    }
    sort(FI.begin(),FI.end());
    int ma = -1;
    for(int c1 = 0; c1 < n; c1++){
        int a = FI[c1].second;
        ANS[a] = max(0, D[a] - max(FI[c1].first,ma));
        ma = max(ma,D[a]);
    }
    for(int c1 = 0; c1 < n; c1++){
        cout << ANS[c1] << "\n";
    }
    return 0;
}

