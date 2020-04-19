#include<bits/stdc++.h>
using namespace std;

int n;
char str[10010];
char ans[10010];
char tmp[10010];
int ansk;

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        scanf("%d", &n);
        scanf("%s", str);
        ans[n] = tmp[n] = 0;
        strcpy(ans, str); ansk=1;
        for(int k=2; k<=n; ++k){
            for(int i=0; i<=n-k; ++i){
                tmp[i] = str[i+k-1];
            }
            if((n-k+1)&1){
                for(int i=0; i<k-1; ++i){
                    tmp[n-i-1] = str[i];
                }
            }
            else{
                for(int i=0; i<k-1; ++i){
                    tmp[n-k+i+1] = str[i];
                }
            }
            if(strcmp(ans, tmp) > 0){
                strcpy(ans, tmp);
                ansk = k;
            }
        }
        printf("%s\n%d\n", ans, ansk);
    }
}