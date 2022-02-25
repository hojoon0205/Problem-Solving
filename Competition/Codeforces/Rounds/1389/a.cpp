#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int l, r, x, y;
        scanf("%d%d", &l, &r);
        if(r/2 >= l){
            printf("%d %d\n", l, l*2);
        }
        else printf("-1 -1\n");
    }
}