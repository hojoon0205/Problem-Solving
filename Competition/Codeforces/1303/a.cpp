#include<bits/stdc++.h>
using namespace std;

char str[100010];


int main()
{
    int i, j, tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        scanf("%s", str);
        int l = strlen(str);
        int l1=-1, r1=-2;
        bool bef1 = false;
        for(i=0; i<l; ++i){
            if(!bef1 && str[i]=='1'){ l1 = i; bef1 = true; }
            if(str[i]=='1') r1 = i;
        }
        int ans = 0;
        for(j=l1; j<=r1; ++j){
            ans += (str[j]=='0')?1:0;
        }
        printf("%d\n", ans);
    }
}