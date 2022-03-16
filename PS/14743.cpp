#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1'000'000'007;

ll get_ans(vector<ll> &in, vector<ll> &out){
    ll n = in.size(), m = out.size();
    vector<ll> l(n), r(n);
    for(int i=0,lp=0,rp=0; i<n; ++i){
        while(lp<m && out[lp] < in[i]) ++lp;
        while(rp<m && out[rp] <= in[i]) ++rp;
        l[i] = lp; r[i] = m-rp;
    }
    for(int i=1; i<n; ++i) l[i] = (l[i]+l[i-1])%MOD;
    ll ret = 0;
    for(int i=1; i<n; ++i){
        ret += r[i] * l[i-1];
        ret %= MOD;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m; cin >> n >> m;
    ll x, y; cin >> x >> y;
    vector<ll> x1(n);
    vector<ll> x2(m);
    for(int i=0; i<n; ++i) cin >> x1[i];
    for(int i=0; i<m; ++i) cin >> x2[i];
    sort(x1.begin(), x1.end());
    sort(x2.begin(), x2.end());
    ll ans = get_ans(x1, x2);
    ans = (ans + get_ans(x2, x1))%MOD;
    cout << ans << endl;
}