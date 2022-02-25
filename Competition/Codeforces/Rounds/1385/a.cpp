#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,tt;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int m = max(x,max(y,z));
        int c = 0;
        if(m==x) ++c;
        if(m==y) ++c;
        if(m==z) ++c;
        if(c<2){ printf("NO\n"); continue; }
        if(m!=x){ printf("YES\n%d %d %d\n", x, x, m); }
        else if(m!=y){ printf("YES\n%d %d %d\n", y, y, m); }
        else if(m!=z){ printf("YES\n%d %d %d\n", z, z, m); }
        else{ printf("YES\n%d %d %d\n", m, m, m); }
    }
}