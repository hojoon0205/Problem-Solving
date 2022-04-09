#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        cout << "Case #" << tt << ": " << "\n";
        int R, C; cin >> R >> C;
        string X="..", Y="..";
        for(int i=1; i<C; ++i) X += "+-";
        X += "+";
        for(int i=1; i<C; ++i) Y += "|.";
        Y += "|";
        cout << X << "\n" << Y << "\n";
        X[0] = '+', X[1] = '-';
        Y[0] = '|';
        for(int i=1; i<R; ++i) cout << X << "\n" << Y << "\n";
        cout << X << "\n";
    }
}