#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct C{
    ll k, l;
};

vector<C> a, b;

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n;
        scanf("%d", &n);
        a.clear(); b.clear();
        ll ans = 0;
        for(int i=0; i<n; ++i){
            ll x, y, z;
            scanf("%lld%lld%lld", &x, &y, &z);
            if(x==n || y==z){ ans += y; continue; }
            ll t = min(y,z);
            ans += t; y -= t; z -= t;
            if(z==0) a.push_back({x,y});
            else b.push_back({n-x,z});
        }
        sort(a.begin(), a.end(), [&](C &a, C &b)->bool{return a.k<b.k;});
        sort(b.begin(), b.end(), [&](C &a, C &b)->bool{return a.k<b.k;});
        priority_queue<ll,vector<ll>,greater<ll>> q;
        for(auto c : a){
            if(q.size() >= c.k){
                if(q.top() >= c.l) continue;
                else q.pop();
            }
            q.push(c.l);
        }
        while(!q.empty()){ ans += q.top(); q.pop(); }
        for(auto c : b){
            if(q.size() >= c.k){
                if(q.top() >= c.l) continue;
                else q.pop();
            }
            q.push(c.l);
        }
        while(!q.empty()){ ans += q.top(); q.pop(); }
        printf("%lld\n", ans);
    }
}