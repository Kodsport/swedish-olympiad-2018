#include <bits/stdc++.h>
using namespace std;

#define rep(a, b, c) for(int a = (b); a < (c); a++)
#define all(v) v.begin(), v.end()

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9, mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  n --;

  ll happiness = 0;
  vector<ll> presum(n+1, 0);

  int bjorns = 0;
  rep(i, 0, n) {
    int a;
    cin >> a;
    if (a == 0) { // skip bjorn
      i --;
      bjorns++;
      continue;
    }
    presum[i+1] = presum[i] + a;
    happiness += a*(i + 1);
  }

  if (bjorns == 0) {
    int a;
    cin >> a;
    if (a == 0) {
      bjorns++;
    }
  }
  assert(bjorns == 1);

  ll ans = happiness;
  rep(i, 0, n+1) // enters at position i, move others up
    ans = max(ans, happiness + presum[n] - presum[i]);

  cout << ans << endl;

  return 0;
}
