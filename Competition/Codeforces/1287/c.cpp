#include<bits/stdc++.h>
using namespace std;
int arr[110];
int dp[110][110][110][2];
int nodd, neven;
int main()
{
    int n, s=0;
    scanf("%d", &n);
    neven = n/2; nodd = n - neven;
    for(int i=1; i<=n; ++i){
        scanf("%d", &arr[i]);
        s += arr[i];
        if(arr[i]==0) arr[i] = -1;
        else arr[i]%=2;
    }
    if(n == 1){ printf("0\n"); return 0; }
    if(s == 0){ printf("1\n"); return 0; }
    for(int i=0; i<=100; ++i)
        for(int j=0; j<=100; ++j)
            for(int k=0; k<=100; ++k) dp[i][j][k][0] = dp[i][j][k][1] = 9999;
    
    if(arr[1] == -1){
        if(neven>0) dp[nodd][neven-1][1][0] = 0;
        if(nodd>0)  dp[nodd-1][neven][1][1] = 0;
    }
    else{
        if(arr[1]==0) dp[nodd][neven-1][1][0] = 0;
        else dp[nodd-1][neven][1][1] = 0;
    }

    for(int i=2; i<=n; ++i){
        for(int no=0; no<=nodd; ++no){
            for(int ne=0; ne<=neven; ++ne){
                if(arr[i]!=1) dp[no][ne][i][0] = min(dp[no][ne+1][i-1][0], dp[no][ne+1][i-1][1]+1);
                if(arr[i]!=0) dp[no][ne][i][1] = min(dp[no+1][ne][i-1][0]+1, dp[no+1][ne][i-1][1]);
            }
        }
    }
    printf("%d\n", min(dp[0][0][n][0], dp[0][0][n][1]));
}