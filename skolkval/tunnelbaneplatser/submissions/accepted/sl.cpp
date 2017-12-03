#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int pl = a - min(a,c) + 2*b + 4*c + 4*d;
	cout << (pl + 3) / 4 << endl;
}
