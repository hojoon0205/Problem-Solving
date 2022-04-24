#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[1010][110];
ll dp[1010][110];

inline char gc() {
    static char buf[1 << 16];
    static size_t bc, be;
    if (bc >= be) {
        buf[0] = 0, bc = 0;
        be = fread(buf, 1, sizeof(buf), stdin);
    }
    return buf[bc++];
}
ll readInt() {
    ll a, c;
    while ((a = gc()) < 40);
    if (a == '-') return -readInt();
    while ((c = gc()) >= 48) a = a * 10 + c - 480;
    return a - 48;
}

int main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int T; T = readInt();
    for(int tt=1; tt<=T; ++tt){
        ll N, P;
        N = readInt(); P = readInt();
        for(int i=1; i<=N; ++i){
            for(int j=0; j<P; ++j) a[i][j] = readInt();
        }
        for(int i=1; i<=N; ++i) for(int j=0; j<P; ++j) dp[i][j] = 1e18;
        for(int i=1; i<=N; ++i){
            ll mi = 2e9, ma = -1;
            for(int j=0; j<P; ++j) mi = min(a[i][j],mi), ma = max(a[i][j],ma);
            for(int x=0; x<P; ++x){
                for(int y=0; y<P; ++y){
                    ll t1 = dp[i-1][x] + abs(a[i-1][x] - mi) + (ma-mi) + (ma-a[i][y]);
                    ll t2 = dp[i-1][x] + abs(a[i-1][x] - ma) + (ma-mi) + (a[i][y]-mi);
                    dp[i][y] = min(dp[i][y], min(t1,t2));
                }
            }
        }
        ll ans = dp[N][0];
        for(int i=1; i<P; ++i) ans = min(dp[N][i], ans);
        cout << "Case #" << tt << ": " << ans << "\n";
    }
}