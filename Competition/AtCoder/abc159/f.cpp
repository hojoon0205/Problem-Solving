#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

int arr[3010];

int main()
{
    int n, s;
    scanf("%d%d", &n, &s);
    for(int i=1; i<=n; ++i) scanf("%d", &arr[i]);
    vector<ll> f(s+1), g(s+1);
    f[0] = g[0] = 1;
    for(int i=1; i<=n; ++i){
        int a = arr[i];
        vector<ll> fn(s+1), gn(s+1);
        fn = f; gn = g;
        for(int p=a; p<=s; ++p){
            gn[p] += g[p-a];
            gn[p] %= MOD;
        }
        for(int p=0; p<=s; ++p) fn[p] = (fn[p] + gn[p])%MOD;
        gn[0] = (gn[0] + 1)%MOD;
        f = fn; g = gn;
    }
    printf("%lld\n", f[s]);
}