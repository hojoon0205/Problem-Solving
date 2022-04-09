#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        cout << "Case #" << tt << ": ";
        string S, A;
        cin >> S;
        int N = S.length();
        A = S[N-1];
        bool chk = false;
        for(int i=N-2; i>=0; --i){
            A = S[i] + A;
            if(S[i] < S[i+1]){ A = S[i] + A; chk = true; }
            else if(S[i] == S[i+1] && chk){ A = S[i] + A; }
            else chk = false;
        }
        cout << A << "\n";
    }
}