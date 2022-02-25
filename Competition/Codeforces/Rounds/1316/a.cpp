#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, tt, T, m;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        scanf("%d%d", &n, &m);
        int s = 0;
        for(int i=1; i<=n; ++i){
            int x;
            scanf("%d", &x);
            s += x;
        }
        printf("%d\n", min(m, s));
    }
}