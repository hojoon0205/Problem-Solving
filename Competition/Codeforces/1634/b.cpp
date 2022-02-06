#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        ll n, x, y; cin >> n >> x >> y;
        vector<ll> a(n);
        for(int i=0; i<n; ++i) cin >> a[i];
        ll A = x&1, B = (x+1)&1;
        for(int i=0; i<n; ++i){
            if(a[i]%2==0) continue;
            A^=1; B^=1;
        }
        if((y&1) == A) cout << "Alice\n";
        else cout << "Bob\n";
    }
}