#include <bits/stdc++.h>
using namespace std;

#define rep(x,s,e) for(int x = (s); x < (e); x++)

typedef vector<int> vi;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vi in(n);
  vi sum(n);
  rep(i, 0, n) {
    cin >> in[i];
    sum[i] = in[i];
    if (i > 0)
      sum[i] += sum[i-1];
  }

  int best = 0;
  rep(i, 0, n) {
    int lower = sum[i];
    int upper = sum[n-1] - sum[i] + in[i];
    best = max(best, min(lower, upper));
  }

  cout << best << endl;

  return 0;
}
