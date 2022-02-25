#include<bits/stdc++.h>
using namespace std;

bool chk[501];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n;
        scanf("%d", &n);
        memset(chk, 0, sizeof(chk));
        for(int i=1; i<=2*n; ++i){
            int x;
            scanf("%d", &x);
            if(chk[x]) continue;
            printf("%d ", x);
            chk[x] = true;
        }
        printf("\n");
    }
}