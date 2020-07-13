#include<bits/stdc++.h>
using namespace std;

int a[110];

int main()
{
    int i, N, ans = 0;
    scanf("%d", &N);
    for(int i=1; i<=N; ++i){
        scanf("%d", &a[i]);
        if(i%2 && a[i]%2) ++ans;
    }
    printf("%d\n", ans);
}