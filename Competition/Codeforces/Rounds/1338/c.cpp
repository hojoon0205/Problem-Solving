#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ta[3][4] = {{0,1,2,3},{0,2,3,1},{0,3,1,2}};

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        ll N, ans = 0, I;
        scanf("%lld", &N); --N;
        I = N%3;
        if(I==0) ans = 1;
        else if(I==1) ans = 2;
        else if(I==2) ans = 3;
        N /= 3;
        ll x = 1;
        int c = 0;
        while(true){
            if(N < x) break;
            N -= x; x <<= 2; ++c; ans <<= 2;
        }
        for(int i=0; i<c; ++i){
            ll tmp = 3LL << (2*i);
            ll t = (N&tmp)>>(2*i);
            ans |= (ta[I][t] << (2*i));
        }
        printf("%lld\n", ans);
        fflush(stdout);
    }
}