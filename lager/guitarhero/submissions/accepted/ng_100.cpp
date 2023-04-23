#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
int n,m,q;

vi A,B1,B2,B3;

int compress[1000001] = {0};

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b;
    cin >> n >> m >> q;
    ll prev = -1;
    for(int c1 = 0 ;c1 < n; c1++){
        cin >> a;
        if(c1 > 0){
            A.push_back((prev >= a) - (prev <= a));
        }
        prev = a;
    }
    int nonz = 0;
    for(int c1 = 0; c1 < n-1; c1++){
        if(A[c1] != 0){
            nonz++;
            B1.push_back(A[c1]);
        }
        compress[c1] = nonz-1;
    }
    prev = -1;
    int len = 0;
    for(int c1 = 0; c1 < sz(B1); c1++){
        if(B1[c1] == prev){
            len++;
        }
        else{
            len = 1;
        }
        B2.push_back(len >= m);
        prev = B1[c1];
    }
    B3.push_back(0);
    for(int c1 = 0; c1 < sz(B2); c1++){
        B3.push_back(B3[c1]+B2[c1]);
    }
    for(int c1 = 0; c1 < q; c1++){
        cin >> a >> b;
        if(a == b){
            cout << "ja\n";
            continue;
        }
        a--;
        b-=2;
        int c = a;
        a = compress[a];
        b = compress[b];
        if(A[c] == 0){
            a++;
        }
        a += m-1;
        if(a > b){
            cout << "ja\n";
        }
        else{
            if(B3[b+1]-B3[a] == 0){
                cout << "ja\n";
            }
            else{
                cout << "nej\n";
            }
        }
    }
    return 0;
}
