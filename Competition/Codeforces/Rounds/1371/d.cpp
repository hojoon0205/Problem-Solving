#include<bits/stdc++.h>
using namespace std;

char a[310][310];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n, k;
        scanf("%d%d", &n, &k);
        if(k%n==0){ printf("%d\n", 0); }
        else printf("%d\n", 2);
        memset(a, 0, sizeof(a));
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j) a[i][j]='0';
        }
        int i=0, j=0;
        for(;k--;){
            if(a[i][j]=='1') ++j;
            a[i][j] = '1';
            ++i; ++j;
            i%=n; j%=n;
        }
        for(int i=0; i<n; ++i) printf("%s\n", a[i]);
    }
}