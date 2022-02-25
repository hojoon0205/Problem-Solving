#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int T, tt;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        ll n, k;
        scanf("%lld%lld", &n, &k);
        if(n>=k*k && n%2==k%2) printf("YES\n");
        else printf("NO\n");
    }
}