#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        cout << "Case #" << tt << ": ";
        string I, P; cin >> I >> P;
        int n=I.length(), m=P.length();
        int p=0, q=0;
        for(p=0; p<n; ++p){
            while(q<m && P[q]!=I[p]) ++q;
            if(q>=m) break;
            ++q;
        }
        if(p>=n) cout << m-n << "\n";
        else cout << "IMPOSSIBLE\n";
    }
}