#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
#define fi first
#define se second

int circles[22][360];
int walls[22][360];
int chk[22][360];


inline char gc() { // like getchar ()
    static char buf[1 << 16];
    static size_t bc, be;
    if (bc >= be) {
        buf[0] = 0, bc = 0;
        be = fread(buf, 1, sizeof(buf), stdin);
    }
    return buf[bc++]; // returns 0 on EOF
}
int readInt() {
    int a, c;
    while ((a = gc()) < 40);
    if (a == '-') return -readInt();
    while ((c = gc()) >= 48) a = a * 10 + c - 480;
    return a - 48;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; T = readInt();
    for(;T--;){
        int N; N = readInt();
        memset(circles, 0, sizeof(circles));
        memset(walls, 0, sizeof(walls));
        memset(chk, 0, sizeof(chk));
        for(int i=0; i<N; ++i){
            // string ty;
            // cin >> ty;
            char ty = gc();
            if(ty=='C'){
                int r, a1, a2;
                //cin >> r >> a1 >> a2;
                r = readInt(); a1 = readInt(); a2 = readInt();
                for(int a=a1; a!=a2; a=(a+1)%360) circles[r][a] = 1;
            }
            else if(ty=='S'){
                int r1, r2, a;
                //cin >> r1 >> r2 >> a;
                r1 = readInt(); r2 = readInt(); a = readInt();
                for(int r=r1; r<r2; ++r) walls[r][a] = 1;
            }
            else assert(false);
        }
        for(int a=0; a<360; ++a) chk[0][a] = 1;
        queue<pii> Q;
        int ans = 0;
        for(int a=0; a<360; ++a) Q.push({0,a});
        while(!Q.empty()){
            int r = Q.front().fi, a = Q.front().se;
            if(r==20){ ans = 1; break; }
            Q.pop();
            // (r+1,a)
            if(!circles[r+1][a] && !chk[r+1][a]){
                chk[r+1][a] = 1;
                Q.push({r+1, a});
            }
            // (r-1,a)
            if(r>0 && !circles[r][a] && !chk[r-1][a]){
                chk[r-1][a] = 1;
                Q.push({r-1, a});
            }
            // (r, a+1)
            int na = (a+1)%360;
            if(!walls[r][na] && !chk[r][na]){
                chk[r][na] = 1;
                Q.push({r, na});
            }
            // (r, a-1)
            na = (a+359)%360;
            if(!walls[r][a] && !chk[r][na]){
                chk[r][na] = 1;
                Q.push({r, na});
            }
        }
        //for(int a=0; a<360; ++a) ans |= chk[20][a];
        cout << (ans?"YES\n":"NO\n");
    }
}