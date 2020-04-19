#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll u, v;
int cnt[70];

int main()
{
    scanf("%lld%lld", &u, &v);
    if(u>v || (u%2)!=(v%2)){ printf("-1\n"); return 0; }
    for(int i=0; i<62; ++i)
        cnt[i] = (v>>i)&1;
    for(int i=1; i<62; ++i){
        int x = (u>>i)&1;
        if(cnt[i] < 0){ cnt[i] += 2; cnt[i+1] -= 1; }
        if(cnt[i]%2 == x) continue;
        if(cnt[i]==0 && x == 1){
            cnt[i+1] -= 1;
            cnt[i] += 2;
            cnt[i] -= 1;
            cnt[i-1] += 2;
        }
        else if(cnt[i]==1 && x == 0){
            cnt[i] -= 1;
            cnt[i-1] += 2;
        }
    }
    ll ans[3] = {0,0,0};
    for(int i=0; i<62; ++i){
        if(cnt[i]==0){ continue; }
        if(cnt[i]==1){ ans[0] += (1LL<<i); }
        if(cnt[i]==2){ ans[0] += (1LL<<i); ans[1] += (1LL<<i); }
        if(cnt[i]==3){ ans[0] += (1LL<<i); ans[1] += (1LL<<i); ans[2] += (1LL<<i); }
    }
    printf("%d\n", ans[0]==0?0:(ans[1]==0?1:(ans[2]==0?2:3)));
    if(ans[0]!=0) printf("%lld ", ans[0]);
    if(ans[1]!=0) printf("%lld ", ans[1]);
    if(ans[2]!=0) printf("%lld ", ans[2]);
    printf("\n");
}