#include<bits/stdc++.h>
using namespace std;

int n;
char str[100010];
int idx[30];
int nextt[30][2];//[0]:left, [1]:right

int main()
{
    int i, j;
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        scanf("%s", str);
        n = strlen(str);
        for(i=1; i<=26; ++i){ idx[i] = 10000; nextt[i][0]=nextt[i][1]=0; }
        idx[str[0]-'a'+1] = 0;
        for(i=1; i<n; ++i){
            int prev=str[i-1]-'a'+1, nex=str[i]-'a'+1;
            if(nextt[prev][0] == 0 && nextt[nex][1] == 0 && idx[nex] == 10000){ nextt[prev][0] = nex; nextt[nex][1] = prev; idx[nex] = idx[prev]-1; }
            else if(nextt[prev][0] == nex && nextt[nex][1] == prev && idx[nex] == idx[prev]-1) continue;
            else if(nextt[prev][1] == 0 && nextt[nex][0] == 0 && idx[nex] == 10000){ nextt[prev][1] = nex; nextt[nex][0] = prev; idx[nex] = idx[prev]+1; }
            else if(nextt[prev][1] == nex && nextt[nex][0] == prev && idx[nex] == idx[prev]+1) continue;
            else{ printf("NO\n"); break; }
        }
        if(i<n) continue;
        int mi=9999, ma=-10000;
        for(i=1; i<=26; ++i){
            if(idx[i]==10000) continue;
            ma = max(ma, idx[i]);
            mi = min(mi, idx[i]);
        }
        char ans[27]; ans[26] = '\0';
        int t = 25;
        for(i=1; i<=26; ++i){
            if(idx[i]==10000){ ans[t] = i+'a'-1; --t; }
            else{ ans[idx[i]-mi] = i+'a'-1; }
        }
        printf("YES\n%s\n", ans);
    }
}