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

bool chkbit(ll N, ll K){ return (K==0)?(N==0):((N<K)?false:(!((N-K)&(K-1)))); }
string ANS(1<<20, '0');

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, K; cin >> N >> K;
    vector<ll> B(N);
    for(int i=0; i<N; ++i) cin >> B[i];
    for(int i=0; i<N; ++i){
        ll su = 0;
        for(int j=i; j<N; ++j){
            if(j>i) su += B[j];
            if(su >= 20) break;
            ll b = B[i] * (1LL<<su);
            if(b >= (1LL<<20)) break;
            ll n = N-1 - (i==0?0:1) - (j==N-1?0:1) - (j-i);
            ll k = K - (i==0?0:1) - (j==N-1?0:1);
            if(chkbit(n,k)) ANS[b] ^= 1;
        }
    }
    int p = (1<<20)-1;
    string P = "";
    for(; p>=1 && ANS[p]=='0'; --p);
    for(;p>=0;--p) P += ANS[p];
    cout << P << endl;
}