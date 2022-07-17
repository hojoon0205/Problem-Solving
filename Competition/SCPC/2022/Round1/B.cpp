#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
const ll MOD = 1000000007;

ll fact[500010];
ll invf[500010];

ll comb(ll N, ll R){
    return fact[N]*invf[R]%MOD*invf[N-R]%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fact[0] = 1;
    invf[0] = invf[1] = 1;
    for(int i=1; i<=500000; ++i) fact[i] = (fact[i-1]*i)%MOD;
    for(int i=2; i<=500000; ++i) invf[i] = ((- invf[MOD%i] * (MOD/i))%MOD + MOD)%MOD;
    for(int i=2; i<=500000; ++i) invf[i] = (invf[i-1] * invf[i])%MOD;

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        ll N, K; cin >> N >> K;
        vector<ll> v(N);
        for(int i=0; i<N; ++i) cin >> v[i];
        vector<ll> s(N+1);
        for(int i=1; i<=N; ++i) s[i] = s[i-1] + v[i-1];
        ll D = s[N]/K;
        if(D*K != s[N]){ cout << "Case #" << tt << "\n0\n"; continue; }
        if(D==0){
            ll c = 0;
            for(int i=1; i<N; ++i) c += (s[i]==0?1:0);
            cout << "Case #" << tt << "\n";
            cout << comb(c, K-1) << "\n";
            continue;
        }
        map<ll,ll> cnt;
        cnt[0] = 1;
        for(int i=1; i<N; ++i){
            cnt[s[i]] += cnt[s[i]-D];
            cnt[s[i]] %= MOD;
        }
        cout << "Case #" << tt << "\n";
        cout << cnt[s[N]-D] << "\n";
    }
}