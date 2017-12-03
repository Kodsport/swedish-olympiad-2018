#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int> > F(n);
    vector<int> ANS(n);
    int life;
    bool fail = 0;
    for(int c1 = 0; c1 < n; c1++){
        int d;
        cin >> F[c1].first >> d;
        F[c1].second = c1;
        ANS[c1] = 0;
        if(c1 == 0)life = d-F[c1].first;
        if(d > 300000 || d-F[c1].first != life)fail = 1;
    }
    sort(F.begin(), F.end());
    int prev = -1000000000;
    for(int c1 = 0; c1 < n; c1++){
        ANS[F[c1].second] = min(F[c1].first - prev,life);
        prev = F[c1].first;
    }

    if(fail){
        cout << "error";
    }
    else{
        for(int c1 = 0; c1 < n; c1++){
            cout << ANS[c1] << "\n";
        }
    }

    return 0;
}

