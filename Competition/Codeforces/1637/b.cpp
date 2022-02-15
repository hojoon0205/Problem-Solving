#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        int n; cin >> n;
        vi a(n);
        for(int i=0; i<n; ++i) cin >> a[i];
        ll ans = 0;
        for(int l=0; l<n; ++l){
            int c = 1;
            for(int r=l; r<n; ++r,++c){
                if(a[r]==0) ++c;
                ans += c;
            }
        }
        cout << ans << "\n";
    }
}