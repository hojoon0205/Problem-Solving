#include<bits/stdc++.h>
using namespace std;

int n, k;

int main(){
    int T;
    scanf("%d", &T);
    for(;T--;){
        scanf("%d%d", &n, &k);
        if(k%2==1 && n%2==0){
            if(n<2*k){ printf("NO\n"); continue; }
            else{
                printf("YES\n");
                for(int i=1; i<k; ++i) printf("2 ");
                printf("%d\n", n-2*(k-1));
                continue;
            }
        }
        else if((k%2==0 && n%2==1) || n<k){ printf("NO\n"); continue; }
        printf("YES\n");
        for(int i=1; i<k; ++i) printf("1 ");
        printf("%d\n", n-(k-1));
    }
}