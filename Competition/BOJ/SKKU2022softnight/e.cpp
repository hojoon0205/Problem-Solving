#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define fi first
#define se second

ll f(ll N){
    ll ret = 0;
    for(ll i=1,x=-1; i<=N; ++i,x=-x){
        ret += x*(N/i);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll S, T;
    cin >> S >> T;
    cout << f(T) - f(S-1) << endl;
}