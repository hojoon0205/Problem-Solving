#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll tt, T;
    scanf("%lld", &T);
    for(tt=1; tt<=T; ++tt){
        ll a, b, x, y;
        scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
        ll x1 = (x+y)*a, x2 = min(x,y)*b + abs(x-y)*a;
        printf("%lld\n", min(x1,x2));
    }
}