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
int n,m,k,T,q;

string s;
int F[26] = {0};

vector<vector<bool> > GC;
bool C[1000001] = {0};
ll nc = 0;
void generate_cuts(int length, int cuts, bool last){
    if(length == 0){
        if(cuts < 0)return;
        vector<bool> temp;
        for(int c1 = 0; c1 < nc; c1++){
            temp.push_back(C[c1]);
        }
        GC.push_back(temp);
        return;
    }
    C[nc] = last;
    nc++;
    generate_cuts(length-1,cuts,last);
    if(cuts != 0){
        C[nc-1] = (last^1);
        generate_cuts(length-1,cuts-1,last^1);
    }
    nc--;
    return;
}

// hashing mod 2^64. fine because the strings we hash are very short (<= 26 chars)
typedef unsigned long long ull;
ull base = 3331;

bool test(int cuts){

    if(cuts == 1){
        int F2[26] = {0};
        for(int c1 = 0; c1 < n/2; c1++){
            F2[s[c1]-'a']++;
        }
        for(int c1 = 0; c1 < 26; c1++){
            if(F2[c1] != F[c1]/2)return 0;
        }
        return 1;
    }
    if(cuts == 2){
        int F2[26] = {0};
        int same = 0;
        for(int c1 = 0; c1 < n/2; c1++){
            F2[s[c1]-'a']++;
        }
        for(int c1 = 0; c1 < 26; c1++){
            same += (F[c1]/2 == F2[c1]);
        }
        if(same == 26)return 1;
        for(int c1 = n/2; c1 < n; c1++){
            int l = s[c1-n/2]-'a';
            int r = s[c1]-'a';
            F2[r]++;
            if(F2[r]-1 == F[r]/2)same--;
            if(F2[r] == F[r]/2)same++;
            F2[l]--;
            if(F2[l]+1 == F[l]/2)same--;
            if(F2[l] == F[l]/2)same++;
            if(same == 26)return 1;
        }
        return 0;
    }

    for(int c1 = cuts/2; c1 < n-cuts/2; c1++){
        unordered_set<ull> S;
        GC.clear();
        nc = 0;
        generate_cuts(c1,cuts/2,0);
        for(int c2 = 0; c2 < sz(GC); c2++){
            int F2[26] = {0};
            for(int c3 = 0; c3 < sz(GC[c2]); c3++){
                if(GC[c2][c3] == 0)F2[s[c3]-'a']++;

            }
            ull has = 0;
            for(int c3 = 0; c3 < m; c3++){
                has *= base;
                has += (F[c3]/2-F2[c3]);
            }

            S.insert(has);
        }
        GC.clear();
        nc = 0;
        generate_cuts(n-c1,cuts/2, (((cuts/2))^cuts)%2 );
        for(int c2 = 0; c2 < sz(GC); c2++){
            int F2[26] = {0};
            for(int c3 = 0; c3 < sz(GC[c2]); c3++){
                if(GC[c2][c3] == 0)F2[s[c3+c1]-'a']++;
            }

            ull has = 0;
            for(int c3 = 0; c3 < m; c3++){
                has *= base;
                has += (F2[c3]);
            }

            if(S.find(has) != S.end())return 1;
        }
    }
    return 0;
}

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> s;

    n = s.length();
    m = 0;
    bool fail = 0;
    for(int c1 = 0; c1 < n; c1++){
        m = max(m, s[c1]-'a'+1);
        F[s[c1]-'a']++;
    }
    int differentletters = 0;
    for(int c1 = 0; c1 < 26; c1++){
        if(F[c1]%2 == 1)fail = 1;
        differentletters += (F[c1] != 0);
    }
    assert(differentletters == m);
    assert(m <= 12);
    if(fail){
        cout << "-1\n";
        return 0;
    }

    int lo = 0;
    int hi = m;

    while(lo < hi-1){
        int mid = (hi+lo)/2;
        if(test(mid)){
            hi = mid;
        }
        else{
            lo = mid;
        }
    }
    cout << hi << "\n";

    return 0;
}
