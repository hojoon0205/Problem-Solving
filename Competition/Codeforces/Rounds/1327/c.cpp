#include<bits/stdc++.h>
using namespace std;

int n, m;
char str[80010];

int main()
{
    scanf("%d%d", &n, &m);
    printf("%d\n", n*m+n+m-3);
    int l=0;
    for(int i=1; i<=n-1; ++i) str[l++] = 'U';
    for(int i=1; i<=m-1; ++i) str[l++] = 'L';
    for(int i=1; i<=n; ++i){
        if(i&1){
            for(int j=1; j<m; ++j) str[l++] = 'R';
        }
        else{
            for(int j=m; j>1; --j) str[l++] = 'L';
        }
        if(i<n) str[l++] = 'D';
    }
    printf("%s\n", str);
}