#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m[6], w[6], hs, hu;
    scanf("%d%d%d%d%d", &m[1], &m[2], &m[3], &m[4], &m[5]);
    scanf("%d%d%d%d%d", &w[1], &w[2], &w[3], &w[4], &w[5]);
    scanf("%d%d", &hs, &hu);
    int ans = 0;
    for(int i=1; i<=5; ++i)
    {
        int x = i*500;
        ans += max(x*3/10, x - (x*m[i]/250)-50*w[i]);
    }
    ans += hs*100 - 50*hu;
    printf("%d\n", ans);
}