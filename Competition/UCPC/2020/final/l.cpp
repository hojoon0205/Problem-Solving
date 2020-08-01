#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define F first
#define S second

int n, arr[1010], Su;
int dp[1010][1010][210];

pii back(int l, int r, pii eat){
    //printf("%d %d %d %d\n", l, r, eat.F, eat.S);
    int dt = eat.F - eat.S + 100;
    if(dp[l][r][dt]!=0){
        // if(eat.F <= eat.S) return dp[l][r][dt];
        // else return {dp[l][r][dt].S, dp[l][r][dt].F};
        return {dp[l][r][dt], Su - dp[l][r][dt]};
    }
    if(l==r){
        if(eat.F <= eat.S) return {eat.F+arr[l], eat.S};
        else return {eat.F, eat.S+arr[l]};
    }
    int nl=l, nr=r;
    pii neat = eat, resl, resr, ret;
    // eat left
    if(eat.F <= eat.S) neat = {eat.F+arr[l], eat.S};
    else neat = {eat.F, eat.S+arr[l]};
    nl = l+1; if(nl>n) nl-=n;
    resl = back(nl, nr, neat);
    // eat right
    nl = l; nr = r; neat = eat;
    if(eat.F <= eat.S) neat = {eat.F+arr[r], eat.S};
    else neat = {eat.F, eat.S+arr[r]};
    nr = r-1; if(nr<1) nr+=n;
    resr = back(nl, nr, neat);
    if(eat.F <= eat.S) ret = max(resl, resr);
    else ret = min(resl, resr);
    // if(eat.F <= eat.S) dp[l][r][abs(eat.F - eat.S)] = ret;
    // else dp[l][r][abs(eat.F - eat.S)] = {ret.S, ret.F};
    dp[l][r][eat.F - eat.S + 100] = ret.F;
    return ret;
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){ scanf("%d", &arr[i]); Su += arr[i]; }
    int ans = 0;
    for(int i=1; i<=n; ++i){
        ans = max(ans, back((i+1)>n?1:(i+1), (i-1)<1?n:(i-1), {arr[i],0}).F);
    }
    printf("%d\n", ans);
    // for(int i=1; i<=n; ++i){
    //     for(int j=1; j<=n; ++j){
    //         for(int dt=0; dt<=100; ++dt){
    //             if(dp[i][j][dt]==make_pair(0,0)) continue;
    //             printf("%d %d %d : {%d, %d}\n", i, j, dt, dp[i][j][dt].F, dp[i][j][dt].S);
    //         }
    //     }
    // }
}