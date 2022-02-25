#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N; cin >> N;
    ll ans=0, p=1;
    while(N){
        ans += (N%7)*p;
        N/=7; p*=3;
    }
    cout << ans << endl;
}