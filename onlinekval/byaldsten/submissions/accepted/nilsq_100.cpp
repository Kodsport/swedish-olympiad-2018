#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> ind;
vector<int> date;
vector<int> kind;
vector<int> person;
bool dead[100001] = {0};
int ANS[100001] = {0};

bool comp(int i, int j){
    return date[i] < date[j];
}

int main()
{
    cin >> n;
    for(int c1 = 0; c1 < n; c1++){
        int a,b;
        cin >> a >> b;
        date.push_back(a);
        date.push_back(b);
        kind.push_back(0);
        kind.push_back(1);
        person.push_back(c1);
        person.push_back(c1);
        ind.push_back(ind.size());
        ind.push_back(ind.size());
    }
    sort(ind.begin(),ind.end(), comp);
    queue<int> Q;
    int prev = -1;
    for(int c1 = 0; c1 < 2*n; c1++){
        int i = ind[c1];
        if(!Q.empty()){
            ANS[Q.front()] += date[i]-prev;
        }
        if(kind[i] == 0){
            Q.push(person[i]);
        }
        else{
            dead[person[i]] = 1;
            if(!Q.empty()){
                while(dead[Q.front()]){
                    Q.pop();
                    if(Q.empty())break;
                }
            }
        }
        prev = date[i];
    }

    for(int c1 = 0; c1 < n; c1++){
        cout << ANS[c1] << "\n";
    }

    return 0;
}

