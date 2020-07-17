#include<bits/stdc++.h>
using namespace std;

int a[200010];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        bool sw = false, s = false;
        if(n<=2){ printf("0\n"); continue; }
        for(int i=n-1; i>=1; --i){
            if(a[i] == a[i+1]) continue;
            if(a[i] < a[i+1]){
                sw = true; continue;
            }
            if(a[i] > a[i+1]){
                if(sw){ printf("%d\n", i); s = true; break; }
                else continue;
            }
        }
        if(!s) printf("0\n");
    }
}