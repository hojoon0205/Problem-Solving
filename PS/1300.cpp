#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, K; cin >> N >> K;
    ll l = 1, r = N*N;
    while(l<=r){
        ll m = (l+r)/2;
        ll low = 0, sl = 0;
        for(ll i=1; i<=N; ++i){
            sl += min(N, m/i);
            low += min(N, (m-1)/i);
        }
        if(low < K && K <= sl){
            cout << m << endl;
            return 0;
        }
        if(K <= low) r = m-1;
        else l = m+1;
    }
}