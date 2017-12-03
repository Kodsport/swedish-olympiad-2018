#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A;
    for(int c1 = 0; c1 < n; c1++){
        int a;
        cin >> a;
        A.push_back(a);
    }
    int ans = 0;
    for(int c1 = n-2; c1 >= 0; c1--){
        ans = max(0,2*ans+A[c1+1]-A[c1]);
    }
    cout << ans << "\n";
    return 0;
}

