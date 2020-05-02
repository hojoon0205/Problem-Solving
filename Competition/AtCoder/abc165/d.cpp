#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll a, b, n, x, ans;
    scanf("%lld%lld%lld", &a, &b, &n);
    x = b<=n?(b-1):n;
    printf("%lld\n", (a*x/b) - a*(x/b));
}