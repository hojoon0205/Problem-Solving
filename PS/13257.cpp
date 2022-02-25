#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll comb(ll n, ll r){
    ll x = 1;
    for(ll i=1; i<=n; ++i) x *= i;
    for(ll i=1; i<=r; ++i) x /= i;
    for(ll i=1; i<=n-r; ++i) x /= i;
    return x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, C, D, M; cin >> N >> C >> D >> M;
    vector<vector<double>> dp(D,vector<double>(N+1,0.0));
    dp[0][C] = 1.0;
    for(int i=1; i<D; ++i){
        for(int j=C; j<=N; ++j){
            for(int k=C; k<=j; ++k){
                dp[i][j] += dp[i-1][k] * (double)(comb(N-k, j-k) * comb(k, C-j+k)) / (double)comb(N, C);
            }
        }
    }

    cout << fixed;
    cout.precision(20);
    cout << dp[D-1][M] << endl;
}