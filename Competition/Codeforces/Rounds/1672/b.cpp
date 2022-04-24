#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        string S; cin >> S;
        if(S.back() == 'A'){ cout << "NO\n"; continue; }
        int c = 0, ans = 1;
        for(int i=0; i<S.length(); ++i){
            if(S[i]=='A') ++c;
            else{
                --c;
                if(c<0){ ans = 0; break; }
            }
        }
        cout << (ans?"YES\n":"NO\n");
    }
}