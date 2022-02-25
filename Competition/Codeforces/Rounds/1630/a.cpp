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
using min_heap = priority_queue<T,vector<T>,greater<T>>;
#define Fi first
#define Se second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T, tt;
    cin >> T;
    for(;T--;){
        ll n, k;
        cin >> n >> k;
        if(k==0){
            for(int i=0; i<n/2; ++i){
                cout << i << " " << n-1-i << "\n";
            }
        }
        else if(k!=n-1){
            cout << k << " " << n-1 << "\n";
            cout << n-1-k << " " << 0 << "\n";
            for(int i=1; i<n/2; ++i){
                if(i==k || i==n-1-k) continue;
                cout << i << " " << n-1-i << "\n";
            }
        }
        else if(n==4) cout << "-1\n";
        else{
            cout << n-2 << " " << n-1 << "\n";
            cout << 1 << " " << n-3 << "\n";
            cout << "0 2\n";
            for(int i=3; i<n/2; ++i) cout << i << " " << n-i-1 << "\n";
        }
    }
}