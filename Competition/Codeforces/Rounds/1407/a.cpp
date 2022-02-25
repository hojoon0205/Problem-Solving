#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        int s = 0;
        for(int i=0; i<n; ++i){
            scanf("%d", &a[i]);
            s += a[i];
        }
        if(s <= n/2){
            printf("%d\n", n/2);
            for(int i=0; i<n/2; ++i) printf("0 ");
            printf("\n");
            continue;
        }
        if((n/2) % 2 == 0){
            printf("%d\n", n/2);
            for(int i=0; i<n/2; ++i) printf("1 ");
            printf("\n"); continue;
        }
        printf("%d\n", n/2+1);
        for(int i=0; i<=n/2; ++i) printf("1 ");
        printf("\n");
    }
}