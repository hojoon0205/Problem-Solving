#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(;T--;){
        int n; cin >> n;
        vector<ll> a(n), b(n);
        for(int i=0; i<n; ++i) cin >> a[i];
        for(int i=0; i<n; ++i) cin >> b[i];
        ll ans = min(abs(a[0]-b[0])+abs(a[n-1]-b[n-1]), abs(a[0]-b[n-1])+abs(a[n-1]-b[0]));
        ll a0=2e9, an=2e9, b0=2e9, bn=2e9;
        for(int i=0; i<n; ++i){
            a0 = min(a0, abs(a[0]-b[i]));
            an = min(an, abs(a[n-1]-b[i]));
            b0 = min(b0, abs(b[0]-a[i]));
            bn = min(bn, abs(b[n-1]-a[i]));
        }
        ans = min(ans, a0+an+b0+bn);
        ans = min(ans, abs(a[0]-b[0])+an+bn);
        ans = min(ans, abs(a[0]-b[n-1])+an+b0);
        ans = min(ans, abs(a[n-1]-b[0])+a0+bn);
        ans = min(ans, abs(a[n-1]-b[n-1])+a0+b0);
        cout << ans << "\n";
    }
}