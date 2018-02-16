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

vi bussar;
vi tabell;
vi bussar2;
int dag = 24*60*60;
int mods[6] = {10,6,10,6,10,10};

void printtime(int tid){
    int t2 = tid;
    vi times;
    for(int c1 = 0; c1 < 6; c1++){
        times.push_back(t2%mods[c1]);
        t2/=mods[c1];
    }
    for(int c1 = 5; c1 >= 0; c1--){
        cout << times[c1];
        if(c1 == 4 || c1 == 2)cout << ":";
    }
    cout << " ";
    return;
}

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,d;

    cin >> n >> m;
    int l = 0;
    bool valid = 1;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        if(c1 == 0 && a >= dag)valid = 0;
        bussar.push_back(a);
        if(a >= dag){
            if(a%dag != bussar[l]%dag)valid = 0;
            l++;
        }
        else{
            bussar2.push_back(a);
        }
    }

    for(int c1 = 0; c1 < m; c1++){
        string s;
        cin >> s;
        a = (s[0]-'0')*60*60*10+(s[1]-'0')*60*60+(s[3]-'0')*60*10+(s[4]-'0')*60+(s[6]-'0')*10+(s[7]-'0');
        tabell.push_back(a);
    }
    if(!valid){
        cout << "fel\n";
    }
    else{
        vi answers;
        int b0 = bussar2[0];
        for(int c1 = 0; c1 < m; c1++){
            bool yes = 1;
            if((dag + tabell[c1] - tabell[(c1-1+m)%m])%dag <= b0 && m > 1)yes = 0;
            for(int c2 = 0; c2 < sz(bussar2); c2++){
                if((bussar2[c2]-b0 + tabell[c1])%dag != tabell[(c1+c2)%m])yes = 0;
            }
            if(yes){
                answers.push_back((tabell[c1]-b0+dag)%dag);
            }
        }
        if(sz(answers) == 0){
            cout << "fel\n";
            return 0;
        }
        sort(all(answers));
        for(int c1 = 0; c1 < sz(answers); c1++){
            printtime(answers[c1]);
        }
    }

    return 0;
}
