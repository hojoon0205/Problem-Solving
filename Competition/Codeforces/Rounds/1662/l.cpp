#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
#define fi first
#define se second

int N;
pll a[200010];

set<pll> D[200010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll v;
    cin >> N >> v;
    for(int i=0; i<N; ++i){
        ll t; cin >> t;
        a[i] = {t*v, t*v};
    }
    for(int i=0; i<N; ++i){
        ll aa; cin >> aa;
        a[i].fi += aa;
        a[i].se -= aa;
    }
    //for(int i=0; i<N; ++i) cout << a[i].fi << " " << a[i].se << endl;
    D[0].insert({0,0});
    int maxD = 0;
    for(int i=0; i<N; ++i){
        int L=0, R=maxD, dp=-1;
        while(L<=R){
            int M = (L+R)/2;
            set<pll>::iterator it = D[M].lower_bound(a[i]);
            if(it==D[M].begin()){ R = M-1; continue; }
            --it;
            if(it->fi <= a[i].fi && it->se <= a[i].se){
                dp = M;
                L = M+1;
            }
            else R = M-1;
        }
        ++dp;
        if(dp==0) continue;
        //cout << i << ": " << dp << endl;
        maxD = max(maxD, dp);
        D[dp].insert(a[i]);
        set<pll>::iterator it = D[dp].find(a[i]);
        if(it != D[dp].begin()){
            auto bef = it; --bef;
            if(bef->fi <= a[i].fi && bef->se <= a[i].se){
                D[dp].erase(it);
                continue;
            }
        }
        for(++it; it != D[dp].end(); ){
            if(it->fi >= a[i].fi && it->se >= a[i].se) D[dp].erase(it++);
            else break;
        }
    }
    cout << maxD << endl;
}