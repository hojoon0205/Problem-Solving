#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, q; cin >> n >> q;
    vector<ll> a(n+1);
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a.begin()+1, a.end(), greater<ll>());
    for(int i=1; i<=n; ++i) a[i] += a[i-1];
    for(;q--;){
        ll x, y;
        cin >> x >> y;
        cout << a[x]-a[x-y] << "\n";
    }
}