#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1000000007;

ll fact[300010];
ll inv[300010];
ll invf[300010];

void init(ll N){
    fact[0] = fact[1] = 1;
    for(ll i=2; i<=2*N; ++i) fact[i] = (fact[i-1] * i)%MOD;
    inv[1] = 1;
    for(ll i=2; i<=2*N; ++i) inv[i] = (-(inv[MOD%i] * (MOD/i) % MOD) + MOD)%MOD;
    invf[0] = invf[1] = 1;
    for(ll i=2; i<=2*N; ++i) invf[i] = (invf[i-1] * inv[i])%MOD;
    return;
}
ll catalan(ll N){
    if(N<=1) return 1;
    return (fact[2*N]*invf[N]%MOD)*invf[N+1]% MOD;
}

string S;
int st[300010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    init(150003);

    string _S;
    cin >> _S;
    for(int i=1; i<(int)_S.length(); i+=2) S += _S[i];
    int d = 0;
    ll ans = 1;
    for(int i=0; i<S.length(); ++i){
        if(S[i]=='?'){
            ++d;
            st[d] = 0;
        }
        else{
            ans = (ans * catalan(st[d])) % MOD;
            --d;
            ++st[d];
        }
    }
    ans = (ans * catalan(st[0])) % MOD;
    cout << ans << endl;
}