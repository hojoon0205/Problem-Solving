#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        char str[200];
        scanf("%s", str);
        int l = strlen(str);
        int x = 0;
        for(int i=0; i<l; ++i) x |= (1<<(str[i]-'0'));
        if(x==3){
            for(int i=0; i<2*l; ++i) printf("%d", i&1);
            printf("\n");
        }
        else printf("%s\n", str);
    }
}