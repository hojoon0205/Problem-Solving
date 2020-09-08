#include<bits/stdc++.h>
using namespace std;

int n;
int ans[100010];

int main()
{
    scanf("%d", &n);
    int u = 1;
    for(int i=2; i<=n; ++i){
        int umi, imu;
        printf("? %d %d\n", u, i); fflush(stdout);
        scanf("%d", &umi);
        printf("? %d %d\n", i, u); fflush(stdout);
        scanf("%d", &imu);
        if(umi > imu){
            ans[u] = umi;
            u = i;
        }
        else{
            ans[i] = imu;
        }
    }
    ans[u] = n;
    printf("!");
    for(int i=1; i<=n; ++i) printf(" %d", ans[i]);
    printf("\n"); fflush(stdout);
    scanf("%d", &u);
}