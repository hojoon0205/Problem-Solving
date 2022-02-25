#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll arr[100010];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%lld", &arr[i]);
        ll m = arr[1], t = 0;
        for(int i=2; i<=n; ++i){
            m = max(arr[i], m);
            t = max(t, m - arr[i]);
        }
        for(int ans=0; ans<40; ++ans){
            if(t < (1LL<<ans)){
                printf("%d\n", ans);
                break;
            }
        }
    }
}