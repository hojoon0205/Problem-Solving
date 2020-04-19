#include<bits/stdc++.h>
using namespace std;

char str[4];

int main()
{
    int i;
    int n, m;
    scanf("%d%d", &n, &m);
    str[n] = 0;
    for(int i=1; i<=m; ++i){
        int s, x;
        scanf("%d%d", &s, &x);
        if(str[s-1] != 0){
            if(str[s-1] != x+'0'){
                printf("-1\n"); return 0;
            }
        }
        str[s-1] = x + '0';
    }
    if(n>1 && (str[0]==0 || str[0]=='1')) str[0] = '1';
    if(n>1 && str[0]=='0'){ printf("-1\n"); return 0; }
    for(int i=(n==1?0:1); i<n; ++i) str[i] = (str[i]==0)?'0':str[i];
    printf("%s\n", str);
}
