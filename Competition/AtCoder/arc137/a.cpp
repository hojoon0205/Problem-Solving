#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll L, R; cin >> L >> R;
    for(ll k=R-L; k>=1; --k){
        for(ll x=L; x+k<=R; ++x){
            if(__gcd(x,x+k) == 1){ cout << k << endl; return 0; }
        }
    }
}