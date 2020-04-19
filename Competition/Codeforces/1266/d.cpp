#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
ll c[100010];
int l[100010], g[100010], cl, cg;
ll ans[200010][3];
int main()
{
    int i, j;
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; ++i){
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);
        c[a] -= d;
        c[b] += d;
    }
    for(int i=1; i<=n; ++i){
        if(c[i]<0) l[++cl] = i;
        if(c[i]>0) g[++cg] = i;
    }
    int ansm = 0, lc=1, gc=1;
    while(lc <= cl && gc <= cg){
        int u = l[lc], v = g[gc];
        ll d = min(-c[u], c[v]);
        ++ansm;
        ans[ansm][0] = u; ans[ansm][1] = v; ans[ansm][2] = d;
        c[u] += d;
        c[v] -= d;
        if(c[u] == 0) ++lc;
        if(c[v] == 0) ++gc;
    }
    printf("%d\n", ansm);
    for(int i=1; i<=ansm; ++i){
        printf("%lld %lld %lld\n", ans[i][0], ans[i][1], ans[i][2]);
    }
}