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
  int maxIn = -1e9;
  rep(i, 0, n) {
    cin >> in[i];
    maxIn = max(maxIn, in[i]);
  }

  vi maxLeft(n);
  rep(i, 0, n) {
    maxLeft[i] = in[i];
    if (i > 0)
      maxLeft[i] += maxLeft[i-1];
    if (maxLeft[i] < 0)
      maxLeft[i] = 0;
  }

  vi maxRight(n);
  for (int i = n-1; i >= 0; i--) {
    maxRight[i] = in[i];
    if (i < n-1)
      maxRight[i] += maxRight[i+1];
    if (maxRight[i] < 0)
      maxRight[i] = 0;
  }

  int best = 0;
  rep(i, 0, n) {
    best = max(best, min(maxLeft[i], maxRight[i]));
  }

  // Handle all negative
  if (maxIn < 0)
    best = maxIn;

  cout << best << endl;

  return 0;
}
