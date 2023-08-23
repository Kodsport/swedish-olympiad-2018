#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> A;
int DP[2001][2001] = {0};
bool DPC[2001][2001] = {0};

int dp(int i, int varv){
    int varv2 = varv-1000;
    if(i == m)return abs(A[i]+n*varv2);
    if(DPC[i][varv])return DP[i][varv];
    int ans = (A[i+1]-A[i]+n)%n + dp(i+1,varv+(A[i+1] < A[i]));
    ans = min(ans, (A[i]-A[i+1]+n)%n + dp(i+1,varv-(A[i+1] > A[i])));
    DPC[i][varv] = 1;
    DP[i][varv] = ans;
    return ans;
}

int main() {
    cin >> n >> m;
    if(m > 1000){
	cout << 0;
	return 0;
    }
    A.push_back(0);
    for(int c1 = 0; c1 < m; c1++){
        int a;
        cin >> a;
        A.push_back(a-1);
    }
    cout << dp(0,1000) << "\n";
    return 0;
}

