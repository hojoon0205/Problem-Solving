#include<bits/stdc++.h>
using namespace std;

int arr[100010];
int ma[100010];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n, k, z;
        scanf("%d%d%d", &n, &k ,&z);
        for(int i=1; i<=n; ++i){
            scanf("%d", &arr[i]);
        }
        for(int i=2; i<=n; ++i) ma[i-1] = arr[i]+arr[i-1];
        int ans = 0;
        for(int b=0; b<=min(z,k/2); ++b){
            int s = 0, m = 0;
            for(int i=1; i<=k+1-2*b; ++i){
                s += arr[i];
                m = max(m, ma[i]);
            }
            s += m*b;
            ans = max(ans, s);
        }
        printf("%d\n", ans);
    }
}