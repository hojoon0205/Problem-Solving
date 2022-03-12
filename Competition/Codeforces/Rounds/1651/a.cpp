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
        cout << ((1<<n)-1) << "\n";
    }
}