#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int X, Y, A, B, C;
vector<ll> p, q, r;

int main()
{
    scanf("%d%d%d%d%d", &X, &Y, &A, &B, &C);
    for(int i=0; i<A; ++i){ ll x; scanf("%lld", &x); p.push_back(x); }
    for(int i=0; i<B; ++i){ ll x; scanf("%lld", &x); q.push_back(x); }
    for(int i=0; i<C; ++i){ ll x; scanf("%lld", &x); r.push_back(x); }
    sort(p.begin(), p.end(), [&](ll a, ll b){ return a>b; });
    sort(q.begin(), q.end(), [&](ll a, ll b){ return a>b; });
    sort(r.begin(), r.end(), [&](ll a, ll b){ return a>b; });
    while(p.size() > X) p.pop_back();
    while(q.size() > Y) q.pop_back();
    int i = 0, xi=X-1, yi=Y-1;
    while(i<C && (xi>=0 || yi>=0)){
        ll tmpx=9999999999, tmpy=9999999999;
        if(xi>=0) tmpx = p[xi];
        if(yi>=0) tmpy = q[yi];
        if(tmpx<tmpy && tmpx<r[i]){ p[xi] = r[i]; ++i; --xi; continue; }
        if(tmpx>tmpy && tmpy<r[i]){ q[yi] = r[i]; ++i; --yi; continue; }
        break;
    }
    ll ans = 0;
    for(auto x : p) ans += x;
    for(auto y : q) ans += y;
    printf("%lld\n", ans);
}