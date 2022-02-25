#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[300010];

int main()
{
    ll n, su = 0, s = 0;
    scanf("%lld", &n);
    for(int i=1; i<=n; ++i){ scanf("%lld", &a[i]); su += a[i]; }
    for(int i=1; i<=n; ++i) s += (i&1)?(a[i]/2):(a[i]/2 + a[i]%2);
    printf("%lld\n", min(s, su-s));
}