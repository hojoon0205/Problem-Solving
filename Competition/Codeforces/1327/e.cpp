#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

ll pow10[300000];

int main()
{
    int n;
    scanf("%d", &n);
    pow10[0] = 1;
    for(int i=1; i<=n; ++i) pow10[i] = (pow10[i-1]*10)%MOD;
    for(int i=n-1; i>=1; --i){
        printf("%lld ", (81*i+99)*pow10[i-1]%MOD);
    }
    printf("10\n");
    puts("qwer");
}