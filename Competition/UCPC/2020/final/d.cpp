#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;
ll ans, l;
ll u[3010], d[3010];

ll dp[3010][3010][2];

ll dist(int ui, int di){
    return l*l + (u[ui]-d[di])*(u[ui]-d[di]);
}

int main()
{
    scanf("%lld%lld%lld", &n, &m, &l);
    for(int i=1; i<=n; ++i) scanf("%lld", &u[i]);
    for(int i=1; i<=m; ++i) scanf("%lld", &d[i]);
    dp[1][1][0] = dp[1][1][1] = dist(1,1) * (n+m-1);
    for(ll i=1; i<=n; ++i){
        for(ll j=1; j<=m; ++j){
            if(i+j==2) continue;
            ll dij = dist(i,j);
            // from dp[i-1][j]
            if(i>1){
                ll tmp0, tmp1;
                tmp0 = dp[i-1][j][0] + dij * (n+m-1);
                tmp1 = dp[i-1][j][1] + dist(i-1,j)*( (i+j-2)*(n+m-i-j+2) - (n+m-1) ) + dij * (n+m-1);
                if(dp[i-1][j][0]==0) dp[i][j][0] = tmp1;
                else if(dp[i-1][j][1]==0) dp[i][j][0] = tmp0;
                else dp[i][j][0] = min(tmp0, tmp1);
            }
            if(j>1){
                ll tmp0, tmp1;
                tmp1 = dp[i][j-1][1] + dij * (n+m-1);
                tmp0 = dp[i][j-1][0] + dist(i,j-1)*( (i+j-2)*(n+m-i-j+2) - (n+m-1) ) + dij * (n+m-1);
                if(dp[i][j-1][0]==0) dp[i][j][1] = tmp1;
                else if(dp[i][j-1][1]==0) dp[i][j][1] = tmp0;
                else dp[i][j][1] = min(tmp0, tmp1);
            }
        }
    }
    if(dp[n][m][0]==0) printf("%lld\n", dp[n][m][1]);
    else if(dp[n][m][1]==0) printf("%lld\n", dp[n][m][0]);
    else printf("%lld\n", min(dp[n][m][0], dp[n][m][1]));
    // for(int i=1; i<=n; ++i){
    //     for(int j=1; j<=m; ++j){
    //         printf("dp[%d][%d][0] = %lld\n", i, j, dp[i][j][0]);
    //         printf("dp[%d][%d][1] = %lld\n", i, j, dp[i][j][1]);
    //     }
    // }
}