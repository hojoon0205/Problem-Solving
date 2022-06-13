#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        ll N, M; cin >> N >> M;
        vector<ll> a(N);
        for(int i=0; i<N; ++i) cin >> a[i];
        ll s = 0;
        for(auto x : a) s += x;
        cout << max(0LL, s-M) << "\n";
    }
}