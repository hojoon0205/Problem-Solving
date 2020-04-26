#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b;
int chk[40010];
ll query(ll x){
    ll ret = 0;
    ret += chk[a*b-1]*(x/a/b);
    x %= (a*b);
    ret += x?chk[x-1]:0;
    return ret;
}

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        ll q;
        scanf("%lld%lld%lld", &a, &b, &q);
        memset(chk, 0, sizeof(chk));
        if(a>b) a^=b^=a^=b;
        for(int i=0; i<a*b; ++i) chk[i] = (i%a%b != i%b%a)?1:0;
        for(int i=1; i<a*b; ++i) chk[i] += chk[i-1];
        while(q--){
            ll x, y;
            scanf("%lld%lld", &x, &y);
            printf("%lld ", query(y+1) - query(x));
        }
        printf("\n");
    }
}