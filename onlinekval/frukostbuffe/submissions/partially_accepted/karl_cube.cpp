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

  int ret = 0;
  rep(i, 0, n) {
    int best = 1e9;
    rep(j, 0, n) {
      int a = i;
      int b = j;
      if (a <= b) {
        vi food = in;
        int eaten = 0;
        while(true) {
          eaten += food[a];
          food[a] = 0;
          if (a + 1 < b)
            a++;
          else
            a--;
          if (a < 0)
            break;

          food[b] = 0;
          if (b != a)
            b--;
        }
        best = min(best, eaten);
      }
      if (a >= b) {
        vi food = in;
        int eaten = 0;
        while(true) {
          eaten += food[a];
          food[a] = 0;
          if (a - 1 > b)
            a--;
          else
            a++;
          if (a >= n)
            break;

          food[b] = 0;
          if (b != a)
            b++;
        }
        best = min(best, eaten);
      }
    }
    ret = max(ret, best);
  }

  cout << ret << endl;

  return 0;
}
