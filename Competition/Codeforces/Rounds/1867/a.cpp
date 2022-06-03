#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        ll n, k; cin >> n >> k;
        vector<ll> a(n);
        for(int i=0; i<n; ++i) cin >> a[i];
        ll ans = 0;
        if(k>=n){
            for(int i=0; i<n; ++i) ans += a[i] + (k-n+i);
        }
        else{
            ans = k*(k-1)/2;
            ll s=0, ma;
            for(int i=0; i<k; ++i) s += a[i];
            ma = s;
            for(int i=k; i<n; ++i){
                s += a[i] - a[i-k];
                ma = max(ma, s);
            }
            ans += ma;
        }
        cout << ans << "\n";
    }
}