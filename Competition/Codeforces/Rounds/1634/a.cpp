#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        int N, K; cin >> N >> K;
        string S; cin >> S;
        string A = S;
        reverse(A.begin(), A.end());
        if(S==A || !K) cout << "1\n";
        else cout << "2\n";
    }
}