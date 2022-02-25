#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll d, m;
ll dp[40][40], a[40];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        scanf("%lld%lld", &d, &m);
        memset(dp, 0, sizeof(dp));
        int s = 0;
        for(s=0; s<40; ++s){
            if(1LL<<s > d) break;
            a[s] = min(1LL<<(s+1), d+1) - (1LL<<s);
        }
        for(int i=0; i<s; ++i){
            dp[1][i] = a[i];
            for(int j=2; j<=i+1; ++j){
                for(int k=0; k<i; ++k){
                    dp[j][i] += dp[j-1][k];
                    dp[j][i] %= m;
                }
                dp[j][i] = (dp[j][i]*a[i])%m;
            }
        }
        ll ans = 0;
        for(int i=0; i<s; ++i){
            for(int j=1; j<=i+1; ++j) ans = (ans+dp[j][i])%m;
        }
        printf("%lld\n", ans);
        
        // printf("dp array\n");
        // for(int i=0; i<=s; ++i){
        //     for(int j=0; j<s; ++j) printf("%lld ", dp[i][j]);
        //     printf("\n");
        // }
        // printf("\n");
    }
}
