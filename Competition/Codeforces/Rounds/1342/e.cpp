#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;
const ll MOD = 998244353;

ll f[200010];
ll inv[200010];

ll comb(ll x, ll y){
    return (((f[x]*inv[y])%MOD)*inv[x-y])%MOD;
}

ll modpow(ll x, ll y){
    ll ret = 1;
    while(y){
        if(y&1) ret = (ret*x)%MOD;
        x = (x*x)%MOD;
        y>>=1;
    }
    return ret;
}

int main()
{
    scanf("%lld%lld", &n, &k);
    if(k>=n){ printf("0\n"); return 0; }
    k = n-k;
    f[0] = 1;
    for(ll i=1; i<=n; ++i) f[i] = (f[i-1]*i)%MOD;
    if(k==n){ printf("%lld\n", f[n]); return 0; }
    inv[0] = inv[1] = 1;
    for(ll i=2; i<=n; ++i) inv[i] = (((inv[MOD%i]*(MOD/i)*(-1))%MOD) + MOD)%MOD;
    for(ll i=2; i<=n; ++i) inv[i] = (inv[i-1]*inv[i])%MOD;
    ll ans = 0;
    for(ll i=1; i<=k; ++i){
        ll tmp = ((k-i)&1)?(MOD-1):1;
        tmp = (tmp*modpow(i, n))%MOD;
        tmp = (tmp*comb(k, i))%MOD;
        ans = (ans+tmp)%MOD;
    }
    printf("%lld\n", ((ans*comb(n,k)%MOD)*2)%MOD);
}