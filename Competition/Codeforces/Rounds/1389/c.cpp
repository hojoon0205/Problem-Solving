#include<bits/stdc++.h>
using namespace std;

char str[200010];

int main()
{
    int T, tt;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int l;
        vector<int> cnt(10, 0);
        scanf("%s", str);
        l = strlen(str);
        for(int i=0; i<l; ++i) ++cnt[str[i]-'0'];
        int ans = l-2;
        for(int i=0; i<10; ++i) ans = min(ans, l-cnt[i]);
        for(int x='0'; x<='9'; ++x){
            for(int y='0'; y<='9'; ++y){
                if(x==y) continue;
                //x, y
                int cur = 0;
                int c = 0;
                for(int i=0; i<l; ++i){
                    if(str[i]!=x && str[i]!=y){ ++c; continue; }
                    if(cur==0){
                        if(str[i]==x) cur ^= 1;
                        else ++c;
                    }
                    else{
                        if(str[i]==y) cur ^= 1;
                        else ++c;
                    }
                }
                if(c%2 != l%2) ++c;
                ans = min(ans, c);
                //y, x
                cur = 1; c = 0;
                for(int i=0; i<l; ++i){
                    if(str[i]!=x && str[i]!=y){ ++c; continue; }
                    if(cur==0){
                        if(str[i]==x) cur ^= 1;
                        else ++c;
                    }
                    else{
                        if(str[i]==y) cur ^= 1;
                        else ++c;
                    }
                }
                if(c%2 != l%2) ++c;
                ans = min(ans, c);
            }
        }
        printf("%d\n", ans);
    }
}