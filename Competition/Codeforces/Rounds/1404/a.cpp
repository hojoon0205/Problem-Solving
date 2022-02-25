#include<bits/stdc++.h>
using namespace std;

char str[300010];
char pat[300010];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s", str);
        memset(pat, 0, sizeof(pat));
        bool chk = true;
        for(int i=0; i<n; ++i){
            if(str[i]=='?') continue;
            if(pat[i%k]==0){ pat[i%k] = str[i]; continue; }
            if(str[i]!=pat[i%k]){
                chk = false; break;
            }
        }
        for(int i=0,c=0; i<k; ++i){
            if(pat[i]=='0') ++c;
            if(c > k/2){ chk = false; break; }
        }
        for(int i=0,c=0; i<k; ++i){
            if(pat[i]=='1') ++c;
            if(c > k/2){ chk = false; break; }
        }
        if(chk) printf("YES\n");
        else printf("NO\n");
    }
}