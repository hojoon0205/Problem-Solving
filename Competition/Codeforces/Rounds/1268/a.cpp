#include<bits/stdc++.h>
using namespace std;

char a[200010];
char ans[200010];

int main()
{
    int i, j;
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", a);
    for(int i=0; i<n; ++i) ans[i] = a[i%k];
    bool sw = true;
    for(int i=0; i<n; ++i){
        if(ans[i] > a[i]) break;
        if(ans[i] < a[i]){ sw = false; break; }
    }
    if(sw){ printf("%d\n%s\n", n, ans); return 0; }
    for(int i=k-1; i>=0; --i){
        if(ans[i]!='9'){
            for(int j=i; j<n; j+=k) ans[j]++;
            break;
        }
        else{
            for(int j=i; j<n; j+=k) ans[j] = '0';
        }
    }
    printf("%d\n%s\n", n, ans);
}