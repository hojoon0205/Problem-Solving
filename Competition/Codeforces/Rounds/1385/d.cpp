#include<bits/stdc++.h>
using namespace std;

char str[200010], tmp[200010];

int solve(int l, int r, char x){
    if(r-l==1){
        return str[l]==x?0:1;
    }
    int m = (l+r)/2;
    int c1=0, c2=0;
    for(int i=l; i<m; ++i) c1 += (str[i]==x)?0:1;
    for(int i=m; i<r; ++i) c2 += (str[i]==x)?0:1;
    return min(c1+solve(m,r,x+1), c2+solve(l,m,x+1));
}

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n;
        scanf("%d", &n);
        scanf("%s", str);
        printf("%d\n", solve(0, n, 'a'));
    }
}