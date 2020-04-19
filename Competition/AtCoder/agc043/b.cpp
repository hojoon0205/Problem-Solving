#include<bits/stdc++.h>
using namespace std;

// nCr % 2
int comb(int n, int r){
    int t = 0;
    int a=n, b=r, c=n-r;
    while(a){ a/=2; t += a; }
    while(b){ b/=2; t -= b; }
    while(c){ c/=2; t -= c; }
    return t?0:1;
}

char str[1000010];

int main()
{
    int n, ans = 0;
    scanf("%d%s", &n, str);
    // only 3
    for(int i=0; i<n; ++i){
        if(str[i]!='3') continue;
        ans ^= comb(n-1, i);
    }
    ans *= 2;
    // only 2
    for(int i=0; i<n; ++i){
        if(str[i]!='2') continue;
        if(ans==2) ans = 0;
        ans ^= comb(n-1, i);
    }
    printf("%d\n", ans);
}