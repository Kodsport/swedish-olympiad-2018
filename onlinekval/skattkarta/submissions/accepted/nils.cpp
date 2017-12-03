#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    string M[100];
    cin >> n >> m;
    for(int c1 = 0; c1 < n; c1++){
        cin >> M[c1];
    }
    int a = 0;
    int b = 0;
    string answer = "cykel";
    for(int c1 = 0; c1 < n*m; c1++){
        if(M[a][b] == 'v'){
            a++;
        }
        else if(M[a][b] == '^'){
            a--;
        }
        else if(M[a][b] == '>'){
            b++;
        }
        else if(M[a][b] == '<'){
            b--;
        }
        else if(M[a][b] == 'A'){
            answer = "sushi";
            break;
        }
        else if(M[a][b] == 'B'){
            answer = "samuraj";
            break;
        }
    }
    cout << answer << "\n";
    return 0;
}
