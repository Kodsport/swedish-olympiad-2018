#include <bits/stdc++.h>
using namespace std;

#define rep(a, b, c) for(int a = (b); a < int(c); a++)
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
  vi v;
  rep(i, 0, n) {
    int a;
    cin >> a;
    if (a != 0)
      v.push_back(a);
  }


  ll ans = -1e18;
  rep(i, 0, n) { // bjorn jumps to position i

    vi nv; // the new queue
    rep(j, 0, i)
      nv.push_back(v[j]);
    nv.push_back(0);
    rep(j, i, v.size())
      nv.push_back(v[j]);

    ll sum = 0;
    rep(j, 0, n)
      sum += nv[j]*(j + 1);
    ans = max(ans, sum);
  }

  cout << ans << endl;

  return 0;
}