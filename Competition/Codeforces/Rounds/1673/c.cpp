#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
#define fi first
#define se second
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

const ll MOD = 1e9+7;
ll dp[40010][510];
vector<ll> pali;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(ll i=1; i<=9; ++i) pali.push_back(i);
    for(ll i=11; i<=99; i+=11) pali.push_back(i);
    for(ll i=1; i<=9; ++i){
        for(ll j=0; j<=9; ++j) pali.push_back(i*101 + j*10);
        for(ll j=0; j<=9; ++j) pali.push_back(i*1001 + j*110);
    }
    for(ll i=1; i<=3; ++i){
        for(ll j=0; j<=9; ++j){
            for(ll k=0; k<=9; ++k) pali.push_back(i*10001 + j*1010 + k*100);
        }
    }
    int M = pali.size();

    for(ll i=0; i<=40000; ++i) dp[i][0] = 1, dp[i][1] = i/2+1;
    for(int k=2; k<M; ++k){
        ll P = pali[k];
        dp[0][k] = 1;
        for(int i=1; i<P; ++i) dp[i][k] = dp[i][k-1];
        for(int i=P; i<=40000; ++i) dp[i][k] = (dp[i][k-1] + dp[i-P][k])%MOD;
    }

    for(;T--;){
        ll N; cin >> N;
        cout << dp[N][M-1] << "\n";
    }
}