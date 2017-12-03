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
  rep(i, 0, n) cin >> in[i];

  int best = 0;
  rep(i, 0, n) {
    int lower = 0;
    int upper = 0;
    rep(j, 0, n) {
      if (j <= i)
        lower += in[j];
      if (j >= i)
        upper += in[j];
    }
    best = max(best, min(lower, upper));
  }

  cout << best << endl;

  return 0;
}
