#include<bits/stdc++.h>
using namespace std;

using ll = long long;
template <typename T>
using max_heap = priority_queue<T>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, K, T; cin >> N >> K >> T;
    vector<ll> arr(N);
    ll S = 0;
    for(int i=0; i<N; ++i){
        cin >> arr[i]; S += arr[i];
    }
    if(S%K != 0){ cout << "NO\n"; return 0; }
    sort(arr.begin(), arr.end());
    int l = 0, r = N-1;
    ll tot = 0;
    while(true){
        while(l<N && arr[l]==0) ++l;
        while(r>=0 && arr[r]%K==0) --r;
        if(l>r) break;
        int d = min(arr[l], K-arr[r]);
        tot += d; arr[l] -= d; arr[r] += d;
    }
    if(tot<=T) cout << "YES\n";
    else cout << "NO\n";
}