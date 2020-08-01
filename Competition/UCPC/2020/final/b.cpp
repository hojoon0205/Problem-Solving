#include<bits/stdc++.h>
using namespace std;

char str[26][200010];
char rows[200010];

int main()
{
    int n, m;
    int l, r;
    int k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0; i<k; ++i){
        scanf("%s", str[i]+1);
    }
    scanf("%s", rows);
    long long ans = 0;
    l = m-1; r = m;
    for(int i=n-1; i>=0; --i){
        int rid = rows[i]-'A';
        //str[rid]
        while(l>=1 && str[rid][l]=='R') --l;
        if(i<n-1){
            while(r>=1 && str[rid][r]=='R') --r;
        }
        ans += (long long)(r-l);
        //printf("%d %d\n", l, r);
    }
    printf("%lld\n", ans);
}