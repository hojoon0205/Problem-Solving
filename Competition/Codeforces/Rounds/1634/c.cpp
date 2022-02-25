#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        int n, k; cin >> n >> k;
        if(k==1){
            cout << "YES\n";
            for(int i=1; i<=n; ++i) cout << i << "\n";
            continue;
        }
        if(n%2){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i=0; i<n; i+=2){
            for(int j=0; j<k; ++j){
                cout << (k*i)+1+j*2 << " ";
            }
            cout << "\n";
            for(int j=0; j<k; ++j){
                cout << (k*i)+2+j*2 << " ";
            }
            cout << "\n";
        }
    }
}