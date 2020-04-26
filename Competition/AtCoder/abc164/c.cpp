#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<string> S;
    int N;
    cin >> N;
    for(int i=1; i<=N; ++i){
        string str;
        cin >> str;
        S.insert(str);
    }
    cout << S.size() << endl;
}