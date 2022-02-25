#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for(;T--;){
        int n;
        scanf("%d", &n);
        if(n<=3){ printf("-1\n"); continue; }
        int s = n/4, r=n%4;
        if(r<=1){
            for(int i=1; i<=s; ++i){
                int a=4*i-3, b=4*i-2, c=4*i-1, d=4*i;
                printf("%d %d %d %d ", b, d, a, c);
            }
            if(r) printf("%d", n);
            printf("\n");
            continue;
        }
        else if(r==2){
            for(int i=1; i<s; ++i){
                int a=4*i-3, b=4*i-2, c=4*i-1, d=4*i;
                printf("%d %d %d %d ", b, d, a, c);
            }
            int a=n-5, b=n-4, c=n-3, d=n-2, e=n-1, f=n;
            printf("%d %d %d %d %d %d\n", b, d, a, e, c, f);
            continue;
        }
        else{
            for(int i=1; i<s; ++i){
                int a=4*i-3, b=4*i-2, c=4*i-1, d=4*i;
                printf("%d %d %d %d ", b, d, a, c);
            }
            int a=n-6, b=n-5, c=n-4, d=n-3, e=n-2, f=n-1, g=n;
            printf("%d %d %d %d %d %d %d\n", b, d, a, e, g, c, f);
            continue;
        }
    }
}