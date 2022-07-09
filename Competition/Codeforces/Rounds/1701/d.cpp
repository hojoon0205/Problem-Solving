#include<bits/stdc++.h>
using namespace std;

using ll = int;
using pll = pair<ll,ll>;
#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        ll N; cin >> N;
        vector<ll> a(N);
        vector<pair<pll,ll>> r(N);
        for(int i=0; i<N; ++i){
            cin >> a[i];
            if(a[i]==0) r[i] = {{i+2, N}, i};
            else r[i] = {{max(1,(i+1)/(a[i]+1) + 1), min((i+1)/a[i],N)}, i};
        }
        sort(r.begin(), r.end(), [&](pair<pll,ll> &x, pair<pll,ll> &y)->bool{
            //return ((!!a[x.se]) == (!!a[y.se]))?(x.fi < y.fi):(a[x.se] > a[y.se]);
            return (x.fi.se==y.fi.se)?(x.fi.fi < y.fi.fi):(x.fi.se < y.fi.se);
        });
        //for(int i=0; i<N; ++i) cout << r[i].fi.fi << " " << r[i].fi.se << ", " << r[i].se << endl;
        vector<ll> ans(N);
        set<ll> S;
        for(int i=1; i<=N; ++i) S.insert(i);
        for(int i=0; i<N; ++i){
            ans[r[i].se] = *S.lower_bound(r[i].fi.fi);
            S.erase(ans[r[i].se]);
        }
        for(int i=0; i<N; ++i) cout << ans[i] << " ";
        cout << "\n";
    }
}