#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S, be, en;
    int sw=1;
    cin >> S;
    int q;
    cin >> q;
    for(;q--;){
        int t;
        cin >> t;
        if(t==1){ sw *= -1; }
        else{
            int f; char c;
            cin >> f >> c;
            if((f==1 && sw==1) || (f==2 && sw==-1)) be = c + be;
            else en += c;
        }
    }
    S = be + S + en;
    if(sw==-1) reverse(S.begin(), S.end());
    cout << S << "\n";
}