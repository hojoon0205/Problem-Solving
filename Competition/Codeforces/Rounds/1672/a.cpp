#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        int N; cin >> N;
        int x = 0;
        for(int i=0; i<N; ++i){
            int t; cin >> t;
            x ^= ((t-1)%2);
        }
        cout << (x?"errorgorn":"maomao90") << "\n";
    }
}