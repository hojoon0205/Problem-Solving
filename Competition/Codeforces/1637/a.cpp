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
        bool ans = true;
        for(int i=0; i<n-1; ++i){
            if(a[i] > a[i+1]) ans = false;
        }
        cout << (ans?"NO":"YES") << "\n";
    }
}