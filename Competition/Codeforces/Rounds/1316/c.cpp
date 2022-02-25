#include<bits/stdc++.h>
using namespace std;
int n, m, p;
int main()
{
    int i, j, mm=-1, nn=-1;
    scanf("%d%d%d", &n, &m, &p);
    for(int i=0; i<n; ++i){
        int x;
        scanf("%d", &x);
        if(mm<0 && x%p) mm=i;
    }
    for(int i=0; i<m; ++i){
        int x;
        scanf("%d", &x);
        if(nn<0 && x%p) nn=i;
    }
    printf("%d\n", mm+nn);
}