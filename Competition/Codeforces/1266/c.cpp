#include<bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    int i, j;
    scanf("%d%d", &n, &m);
    if(n==1 && m==1){ printf("0\n"); return 0; }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            printf("%d ", (n<=m)?((i)*(j+n)):((i+m)*(j)));
        }
        printf("\n");
    }
}