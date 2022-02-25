#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;
ll s = 1;

int main()
{
    ll n, k, t=-1;
    scanf("%lld%lld", &n, &k);
    vector<ll> p;
    for(int i=0; i<n; ++i){
        ll x;
        scanf("%lld", &x);
        p.push_back(x);
        if(x > n-k){
            if(t==-1){
                t = i;
                continue;
            }
            s = (s*(i-t))%MOD;
            t = i;
        }
    }
    printf("%lld %lld\n", k*(n+n-k+1)/2, s);
}