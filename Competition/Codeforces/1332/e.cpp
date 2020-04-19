#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;
const ll inv2 = 499122177;

ll modpow(ll x, ll p){
    ll ret = 1;
    while(p){
        if(p&1) ret = (ret*x)%MOD;
        x = (x*x)%MOD;
        p>>=1;
    }
    return ret;
}

int main()
{
    ll n, m, L, R;
    scanf("%lld%lld%lld%lld", &n, &m, &L, &R);
    ll ans = modpow(R-L+1, n*m);
    if((n*m) % 2) printf("%lld\n", ans);
    else printf("%lld\n", ((ans+((R-L+1)&1))*inv2) % MOD);
}