#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt)
    {
        ll A, B, N, M;
        scanf("%lld%lld%lld%lld", &A, &B, &N, &M);
        if(A+B < N+M){ printf("No\n"); continue; }
        if(min(A,B) < M){ printf("No\n"); continue; }
        printf("Yes\n");
    }
}