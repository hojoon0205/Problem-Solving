#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll arr[100010];

int log_2(ll x){
    ll t=1; int ret=0;
    while(t<x){ t<<=1; ++ret; }
    return ret;
}

struct A
{
    ll val;
    int cnt;
    int spl;
};
A a[1000];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        ll n; int m;
        scanf("%lld%d", &n, &m);
        for(int i=1; i<=m; ++i) scanf("%lld", &arr[i]);
        ll s = 0;
        for(int i=1; i<=m; ++i) s += arr[i];
        if(s < n){ printf("-1\n"); continue; }
        if(s == n){ printf("0\n"); continue; }

        for(int i=0; i<=60; ++i){
            a[i].val = 1LL<<i;
            a[i].cnt = 0;
            a[i].spl = 0;
        }
        
        for(int i=1; i<=m; ++i){
            int t = log_2(arr[i]);
            a[t].cnt ++;
        }
        for(int i=0; i<60; ++i){
            int t = a[i].cnt/2;
            a[i].cnt %= 2;
            a[i+1].cnt += t;
            a[i+1].spl += t;
        }
        ll ans = 0;
        for(int i=60; i>=0; --i){
            if(n < (1LL<<i)) continue;
            n -= (1LL<<i);
            if(a[i].cnt > 0){ --a[i].cnt; continue; }
            int t;
            for(t=i+1; t<=60; ++t){
                if(a[t].cnt > 0) break;
            }
            for(;t>i; --t){
                --a[t].cnt;
                a[t-1].cnt += 2;
                if(a[t].spl>0) --a[t].spl;
                else ++ans;
            }
            --a[i].cnt;
        }
        printf("%lld\n", ans);
    }
}