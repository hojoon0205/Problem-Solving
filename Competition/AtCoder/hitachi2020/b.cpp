#include<bits/stdc++.h>
using namespace std;

int A[100010];
int B[100010];

int main()
{
    int a, b, m, ma=99999999, mb=99999999;
    scanf("%d%d%d", &a, &b, &m);
    for(int i=1; i<=a; ++i){ scanf("%d", &A[i]); ma = min(ma, A[i]); }
    for(int i=1; i<=b; ++i){ scanf("%d", &B[i]); mb = min(mb, B[i]); }
    int ans = ma+mb;
    for(;m--;){
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        ans = min(ans, A[x]+B[y]-c);
    }
    printf("%d\n", ans);
}