#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll nC2(int x){
    return ((ll)(x) * (ll)(x-1)) / 2;
}

int arr[200010];
char str[200010];
int cnt[10010];
int modinv10[200010];

int main()
{
    int i, j, n, p;
    ll ans = 0;
    scanf("%d%d", &n, &p);
    scanf("%s", str+1);
    if(p==2 || p==5){
        for(int i=1; i<=n; ++i){
            int x = str[i]-'0';
            if(x%p == 0) ans += (ll)i;
        }
        printf("%lld\n", ans);
        return 0;
    }
    int inv10;
    for(inv10=1;inv10<p;++inv10){
        if(inv10*10 % p == 1) break;
    }
    modinv10[0] = 1;
    for(int i=1; i<=n; ++i) modinv10[i] = (modinv10[i-1]*inv10)%p;
    ++cnt[0];
    int bef = 0;
    for(int i=1; i<=n; ++i){
        int x = str[i]-'0';
        bef = (bef*10 + x)%p;
        ++cnt[(bef*modinv10[i])%p];
    }
    for(int i=0; i<p; ++i) ans += nC2(cnt[i]);
    printf("%lld\n", ans);
}