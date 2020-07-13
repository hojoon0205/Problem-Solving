#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char str[300010];
ll mod1[300010], mod2[300010];//c+1, c-1

ll popcount(ll num){
    ll ret=0;
    while(num){
        ret += num&1;
        num>>=1;
    }
    return ret;
}

int main()
{
    int n, c=0;
    scanf("%d", &n);
    scanf("%s", str);
    for(int i=0; i<n; ++i) c += str[i]-'0';
    if(c==0){
        for(int i=0; i<n; ++i) printf("1\n");
        return 0;
    }
    for(ll i=0,x=1,y=1; i<n; ++i){
        mod1[i] = x;
        mod2[i] = y;
        x*=2; y*=2;
        x%=c+1;
        if(c<=1) y=0;
        else y%=c-1;
    }
    ll A1=0, A2=0;
    for(int i=0; i<n; ++i){
        A1 += mod1[i]*(str[n-i-1]-'0');
        A1 %= c+1;
        A2 += mod2[i]*(str[n-i-1]-'0');
        if(c<=1) A2 = 0;
        else A2 %= c-1;
    }
    for(int i=0; i<n; ++i){
        int ans = 0;
        if(c==1 && str[i]=='1'){
            printf("0\n");
            continue;
        }
        ll mod = 0;
        if(str[i]=='0'){
            //A1
            mod = A1;
            mod += mod1[n-i-1];
            mod %= c+1;
            ans ++;
            while(mod){
                ll pc = popcount(mod);
                mod %= pc;
                ++ans;
            }
        }
        else{
            //A2
            mod = A2;
            mod -= mod2[n-i-1];
            mod %= c-1;
            mod = (mod+c-1)%(c-1);
            ans ++;
            while(mod){
                ll pc = popcount(mod);
                mod %= pc;
                ++ans;
            }
        }
        printf("%d\n", ans);
    }
}