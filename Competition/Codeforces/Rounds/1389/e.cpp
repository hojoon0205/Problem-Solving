#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll x, ll y){ return y?gcd(y,x%y):x; }

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        ll m, d, w;
        scanf("%lld%lld%lld", &m, &d, &w);
        ll a = w / gcd(w, d-1);
        ll b = min(d,m);
        //printf("%lld %lld\n", a, b);
        ll t = b/a, k = b%a;
        ll ans = ((t+1)*t/2) * k + (t*(t-1)/2) * (a-k);
        printf("%lld\n", ans);
    }
}