#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;

#define pll pair<ll,ll>
#define F first
#define S second
#define MP make_pair

char str[5010];
pll hasho_pre[5010];
pll hasho_post[5010];
pll hashi_pre[5010];
pll hashi_post[5010];
pll pow27[5010];
char ans[5010];

int main()
{
    pow27[0] = {1, 1};
    for(int i=1; i<=5000; ++i)
        pow27[i] = { pow27[i-1].F * 27 % MOD1, pow27[i-1].S * 27 % MOD2 };
    int t;
    scanf("%d", &t);
    for(;t--;){
        scanf("%s", str);
        int l = strlen(str);
        hasho_pre[0] = hashi_pre[0] = {str[0]-'a'+1, str[0]-'a'+1};
        for(int i=1; i<l; ++i){
            ll tmp = str[i]-'a'+1;
            hasho_pre[i].F = (hasho_pre[i-1].F + pow27[i].F*tmp)%MOD1;
            hasho_pre[i].S = (hasho_pre[i-1].S + pow27[i].S*tmp)%MOD2;
            hashi_pre[i].F = (27*hashi_pre[i-1].F + tmp)%MOD1;
            hashi_pre[i].S = (27*hashi_pre[i-1].S + tmp)%MOD2;
        }
        hasho_post[l] = hashi_post[l] = {0,0};
        hasho_post[l-1] = hashi_post[l-1] = {str[l-1]-'a'+1, str[l-1]-'a'+1};
        for(int i=l-2; i>=0; --i){
            ll tmp = str[i]-'a'+1;
            hashi_post[i].F = (hashi_post[i+1].F + pow27[l-1-i].F*tmp)%MOD1;
            hashi_post[i].S = (hashi_post[i+1].S + pow27[l-1-i].S*tmp)%MOD2;
            hasho_post[i].F = (27*hasho_post[i+1].F + tmp)%MOD1;
            hasho_post[i].S = (27*hasho_post[i+1].S + tmp)%MOD2;
        }

        int ma=0, mb=0;
        for(int a=0; a<=l; ++a){
            for(int b=0; b<=l-a; ++b){
                pll ho_pre  = a==0?MP(0LL,0LL):hasho_pre[a-1];
                pll ho_post = b==0?MP(0LL,0LL):hasho_post[l-b];
                pll hi_pre  = a==0?MP(0LL,0LL):hashi_pre[a-1];
                pll hi_post = b==0?MP(0LL,0LL):hashi_post[l-b];
                pll O = MP((ho_pre.F + pow27[a].F * ho_post.F)%MOD1, (ho_pre.S + pow27[a].S * ho_post.S)%MOD2);
                pll I = MP((hi_pre.F * pow27[b].F + hi_post.F)%MOD1, (hi_pre.S * pow27[b].S + hi_post.S)%MOD2);
                if(O != I) continue;
                if(a+b > ma+mb){ ma=a; mb=b; }
            }
        }
        int p = 0, pa=0, pb=l-mb;
        for(; ma||mb; ++p){
            if(ma){ ans[p] = str[pa]; ++pa; --ma; }
            else if(mb) { ans[p] = str[pb]; ++pb; --mb; }
        }
        ans[p] = 0;
        printf("%s\n", ans);
    }
}