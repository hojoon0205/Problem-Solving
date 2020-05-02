#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll modpow(ll x, ll y){ // x^y
    ll ret = 1;
    while(y){
        if(y&1) ret = (ret*x)%MOD;
        x = (x*x)%MOD; y>>=1;
    }
    return ret;
}

bool chk[1000010];
ll cnt[1000010];

int main()
{
    ll p, k;
    scanf("%lld%lld", &p, &k);
    if(k==0){
        printf("%lld\n", modpow(p, p-1));
        return 0;
    }
    else if(k==1){
        printf("%lld\n", modpow(p, p));
        return 0;
    }
    for(int i=1; i<p; ++i){
        if(chk[i]) continue;
        ll x = i, t = 0;
        while(!chk[x]){
            chk[x] = true; ++t;
            x = (x*k)%p;
        }
        ++cnt[t];
    }
    ll ans = 1;
    for(int i=1; i<p; ++i){
        ll tmp = (modpow(cnt[i]*i + 1, cnt[i]))%MOD;
        ans = (ans*tmp)%MOD;
    }
    printf("%lld\n", ans);
}