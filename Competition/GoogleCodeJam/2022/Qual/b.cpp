#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        const int F = 1000000;
        cout << "Case #" << tt << ": ";
        int C=1e7,M=1e7,Y=1e7,K=1e7;
        for(int i=0; i<3; ++i){
            int c, m, y, k; cin >> c >> m >> y >> k;
            C = min(C,c); M = min(M,m);
            Y = min(Y,y); K = min(K,k);
        }
        if(C+M+Y+K < F){ cout << "IMPOSSIBLE\n"; continue; }
        if(C>=F){ cout << F << " 0 0 0\n"; }
        else if(C+M>=F){ cout << C << " " << F-C << " 0 0\n"; }
        else if(C+M+Y>=F){ cout << C << " " << M << " " << F-C-M << " 0\n"; }
        else{ cout << C << " " << M << " " << Y << " " << F-C-M-Y << "\n"; }
    }
}