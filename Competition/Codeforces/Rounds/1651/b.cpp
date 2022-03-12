#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(;T--;){
        int n; cin >> n;
        vector<ll> a(n);
        a[0]=1;
        for(int i=1; i<n; ++i){
            a[i] = a[i-1]*3;
            if(a[i] > 1000000000) a[i] = 1000000001;
        }
        if(a[n-1]==1000000001) cout << "NO\n";
        else{
            cout << "YES\n";
            for(int i=0; i<n; ++i) cout << a[i] << " ";
            cout << "\n";
        }
    }
}