#include<bits/stdc++.h>
using namespace std;

char I[60], O[60];
bool chk[60][60];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n;
        scanf("%d", &n);
        scanf("%s", I);
        scanf("%s", O);
        memset(chk, 0, sizeof(chk));
        for(int i=0; i<n; ++i) chk[i][i] = true;
        for(int i=0; i<n; ++i){
            for(int j=i-1; j>=0; --j){
                if(chk[i][j+1] && (O[j+1]=='Y' && I[j]=='Y')){
                    chk[i][j] = true;
                }
                else break;
            }
            for(int j=i+1; j<n; ++j){
                if(chk[i][j-1] && (O[j-1]=='Y' && I[j]=='Y')){
                    chk[i][j] = true;
                }
                else break;
            }
        }
        printf("Case #%d:\n", tt);
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j) printf("%c", chk[i][j]?'Y':'N');
            printf("\n");
        }
    }
}