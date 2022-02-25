#include<bits/stdc++.h>
using namespace std;

bool dp[2][4010];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n;
        vector<int> a;
        int t = 0, c = 0;
        scanf("%d", &n);
        for(int i=0; i<2*n; ++i){
            int x;
            scanf("%d", &x);
            if(x > t){
                if(t>0) a.push_back(c);
                t = x; c = 1;
            }
            else ++c;
        }
        a.push_back(c);
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for(auto val : a){
            for(int i=0; i<val; ++i) dp[1][i] = dp[0][i];
            for(int i=val; i<=2*n; ++i) dp[1][i] = dp[0][i-val] || dp[0][i];
            for(int i=0; i<2*n; ++i) dp[0][i] = dp[1][i];
        }
        printf("%s\n", dp[0][n]?"YES":"NO");
    }
}