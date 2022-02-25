#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int arr[200010], su[200010];
int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        scanf("%d%d%d", &n, &m, &k);
        for(int i=1; i<=n; ++i){
            scanf("%d", &arr[i]);
        }
        sort(arr+1, arr+n+1);
        su[0] = 0;
        for(int i=1; i<=n; ++i)
            su[i] = su[i-1]+arr[i];
        int ans = 0;
        // not using promotion
        for(int i=1; i<=n; ++i)
            if(su[i]<=m) ans = i;
        // using promotion
        su[0] = 0;
        for(int i=k; i<=n; ++i){
            if(arr[i]>m) break;
            ans = max(ans, k);
            int l=0, r=i-k, mid;
            while(l<=r){
                mid = (l+r)/2;
                if(su[mid]+arr[i] <= m){
                    ans = max(ans, mid+k);
                    l = mid+1;
                }
                else r = mid-1;
            }
        }
        printf("%d\n", ans);
    }
}