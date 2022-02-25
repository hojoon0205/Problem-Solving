#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if(a>b) a^=b^=a^=b;
        c = c-d;
        d = c + 2*d;
        if(c<a) c = a;
        if(d>b) d = b;
        if(c>d) c = d;
        printf("%d\n", b-a-d+c);
    }
}