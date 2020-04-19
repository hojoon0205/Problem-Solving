#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll tt, T, n, g, b;
    scanf("%lld", &T);
    for(tt=1; tt<=T; ++tt){
        scanf("%lld%lld%lld", &n, &g, &b);
        ll numb = n/2;
        ll aa, bb, cc; // g+b, g+.b, g
        aa = (numb / b) * (g+b);
        if(aa >= n){ printf("%lld\n", n); continue; }
        bb = g + numb % b;
        if(aa+bb >= n){ printf("%lld\n", n); continue; }
        ll remain = n-aa-bb;
        cc = (remain%g) ? ((remain/g)*(g+b) + remain%g) : (((remain/g)-1)*(g+b)+g);
        printf("%lld\n", (numb/b + 1)*(g+b) + cc);
        //printf("%lld %lld %lld\n\n", aa, bb, cc);
    }
}