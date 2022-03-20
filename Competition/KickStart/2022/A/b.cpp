#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        cout << "Case #" << tt << ": ";
        string N; cin >> N;
        int s=0, l=N.length();
        for(int i=0; i<l; ++i) s = (s+N[i]-'0')%9;
        if(s==0){
            cout << (N.substr(0,1) + "0" + N.substr(1)) << "\n";
            continue;
        }
        s = 9-s;
        string ANS;
        int p;
        for(p=0; p<l; ++p){
            if(s < N[p]-'0') break;
        }
        ANS = "0"; ANS[0] = '0'+s;
        cout << (N.substr(0,p) + ANS + N.substr(p)) << "\n";;
    }
}