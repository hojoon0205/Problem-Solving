#include<bits/stdc++.h>
using namespace std;

int dp[110][110], n, m;
char arr[110][110];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; ++i) scanf("%s", arr[i]);
    dp[0][0] = arr[0][0]=='#'?1:0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(i+j==0) continue;
            dp[i][j] = 999999;
            if(i>0) dp[i][j] = min(dp[i][j], dp[i-1][j]+((arr[i-1][j]=='.'&&arr[i][j]=='#')?1:0));
            if(j>0) dp[i][j] = min(dp[i][j], dp[i][j-1]+((arr[i][j-1]=='.'&&arr[i][j]=='#')?1:0));
        }
    }
    printf("%d\n", dp[n-1][m-1]);
}