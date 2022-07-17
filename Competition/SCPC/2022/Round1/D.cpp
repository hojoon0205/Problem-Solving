#include<bits/stdc++.h>
using namespace std;

using ll = long long;

bool isContain(string& X, string& Y){
    int lx = X.length(), ly = Y.length();
    if(ly==0) return true;
    if(lx < ly) return false;
    const ll MOD = 1000000007LL * 1000000009LL;
    ll cy = 0, cx = 0, p = 1;
    for(int i=0; i<ly; ++i){
        cy = (cy*2 + Y[i]-'a')%MOD;
        p = (p<<1)%MOD;
    }
    for(int i=0; i<ly; ++i) cx = (cx*2 + X[i]-'a')%MOD;
    if(cx==cy) return true;
    for(int i=ly; i<lx; ++i){
        cx = (cx*2 + X[i]-'a');
        cx = (cx - (X[i-ly]=='b'?p:0) + MOD)%MOD;
        if(cx==cy) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        cout << "Case #" << tt << "\n";

        int N, M; cin >> N >> M;
        string A, B; cin >> A >> B;
        int la=0, ra=N-1;
        int lb=0, rb=M-1; // (l,r)
        for(lb=0; lb<M-1; ++lb,++la){
            while(la<N && A[la]!=B[lb]) ++la;
            if(B[lb] != B[lb+1]) break;
        }
        for(rb=M-1; rb>=lb && rb>0; --rb,--ra){
            while(ra>=0 && A[ra]!=B[rb]) --ra;
            if(B[rb] != B[rb-1]) break;
        }
        if(rb<lb || lb==M-1 || rb==0){
            // B has only one kind of character
            int c = 0;
            for(int i=0; i<N; ++i){
                if(A[i]==B[0]) ++c;
            }
            cout << (c>=M?"YES":"NO") << "\n";
            continue;
        }
        if(la>=N || ra<0 || la>=ra){ cout << "NO\n"; continue; }
        string Y = B.substr(lb+1, rb-lb-1);
        string X = A.substr(la+1, ra-la-1);
        if(isContain(X,Y)) cout << "YES\n";
        else cout << "NO\n";
    }
}