#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        long long N, R;
        scanf("%lld%lld", &N, &R);
        long long ans = min(N-1,R) * (min(N-1,R)+1) / 2;
        if(R>=N) ++ans;
        printf("%lld\n", ans);
    }
}