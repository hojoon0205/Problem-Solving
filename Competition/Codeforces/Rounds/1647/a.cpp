#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        int n; cin >> n;
        string S = "";
        while(n>=3){ S += "21"; n-=3; }
        if(n==1) S = "1"+S;
        else if(n==2) S = S+"2";

        cout << S << "\n";
    }
}