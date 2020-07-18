#include<bits/stdc++.h>
using namespace std;

int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    if(n==2){
        printf("YES\n");
        printf("swap 1 2\n");
        printf("swap 1 2\n");
        printf("swap 1 2\n");
        printf("swap 1 2\n");
        printf("swap 1 2\n");
        return 0;
    }
    if(n==3){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    printf("swap 1 2\n");
    printf("swap 1 2\n");
    if(k==1){
        printf("reverse 1 2\n");
        printf("reverse 3 %d\n", n);
        printf("reverse 2 %d\n", n);
    }
    else if(k==n-1){
        printf("reverse 1 %d\n", n-2);
        printf("reverse %d %d\n", n-1, n);
        printf("reverse 1 %d\n", n-1);
    }
    else{
        printf("reverse 1 %d\n", k);
        printf("reverse %d %d\n", k+1, n);
        printf("reverse 1 %d\n", n);
    }
}