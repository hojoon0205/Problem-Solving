#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pll pair<ll,ll>
#define MP make_pair
#define F first
#define S second

int N, M;
vector<pll> A;

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; ++i){
        ll x, y;
        scanf("%lld%lld", &x, &y);
        A.push_back(MP(x,y));
    }
    sort(A.begin(), A.end());

    ll l=1, r=2000000000000000000LL/N, D;
    while(l<=r){
        ll mid = (l+r)/2;
        ll idx=0, p=A[0].F;
        bool sw = true;
        for(int i=1; i<N; ++i){
            while(idx<M && A[idx].S < p+mid){
                ++idx;
            }
            if(idx>=M){ sw = false; break; }
            p = max(p+mid, A[idx].F);
        }
        if(sw){ D=mid; l=mid+1; }
        else r=mid-1;
    }
    printf("%lld\n", D);
}