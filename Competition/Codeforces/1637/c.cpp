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
        vl a(n);
        for(int i=0; i<n; ++i) cin >> a[i];
        if(n==3){
            if(a[1]%2==1){
                cout << "-1\n";
                continue;
            }
            else{
                cout << a[1]/2 << "\n";
                continue;
            }
        }
        ll co=0, su=0; bool able = false;
        for(int i=1; i<n-1; ++i){
            if(a[i] >= 2) able = true;
            if(a[i]%2==1) ++co;
            su += a[i];
        }
        if(able == false) cout << "-1\n";
        else cout << (co+su)/2 << "\n";
    }
}