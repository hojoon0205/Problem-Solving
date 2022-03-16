#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<ll> arr(N);
    for(int i=0; i<N; ++i) cin >> arr[i];
    int p = 0; ll ans = 0;
    for(int b=60; b>=0; --b){
        int t = -1;
        for(int i=p; i<N; ++i) if((arr[i]>>b)&1) t=i;
        if(t==-1) continue;
        swap(arr[t], arr[p]);
        ll tmp = arr[p];
        for(int i=0; i<N; ++i){
            if(i==p) continue;
            if((arr[i]>>b)&1) arr[i] ^= tmp;
        }
        ++p;
    }
    for(int i=0; i<N; ++i) ans ^= arr[i];
    cout << ans << endl;
}