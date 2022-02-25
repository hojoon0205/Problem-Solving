#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        ll n, k;
        scanf("%lld%lld", &n, &k);
        ll l1, l2, r1, r2;
        scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
        ll mal = max(l1,l2), mil = min(l1,l2);
        ll mar = max(r1,r2), mir = min(r1,r2);
        ll pre = max(0LL, mal-mir);
        ll already = max(0LL, mir-mal);
        ll remain = k - already * n;
        if(remain<=0){ printf("0\n"); continue; }
        ll run = mar-mil - already;
        ll ans = pre*n + 2*remain;
        for(int i=1; i<=n; ++i){
            if(run*i >= remain){
                ans = min(ans, pre*i + remain);
                break;
            }
            ans = min(ans, pre*i + run*i + 2*(remain-run*i));
        }
        printf("%lld\n", ans);
    }
}