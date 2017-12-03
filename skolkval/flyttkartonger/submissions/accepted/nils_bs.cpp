#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> A;

bool test(int d){
    vector<int> B;
    for(int c1 = 0; c1 < n; c1++){
        B.push_back(A[c1]);
    }
    B[0] += d;
    for(int c1 = 0; c1 < n-1; c1++){
        if(B[c1] < B[c1+1])return 0;
        int b = (B[c1]-B[c1+1])/2;
        B[c1]-=b;
        B[c1+1]+=b;
    }
    return 1;
}

int main()
{
    cin >> n;
    for(int c1 = 0; c1 < n; c1++){
        int a;
        cin >> a;
        A.push_back(a);
    }

    int l = 0;
    int r = 1000000000;
    if(test(0)){
        cout << "0\n";
    }
    else{
        while(l < r-1){
            int mid = (l+r)/2;
            if(test(mid)){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        cout << r << "\n";
    }
    return 0;
}

