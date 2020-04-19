#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int a, b, c, d;
        int x, y, x1, y1, x2, y2;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        scanf("%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2);
        x += b-a; y += d-c;
        printf("%s\n", ((x1<=x && x<=x2 && y1<=y && y<=y2) && (a+b==0 || x1<x2) && (c+d==0 || y1<y2))?"Yes":"No");
    }
}