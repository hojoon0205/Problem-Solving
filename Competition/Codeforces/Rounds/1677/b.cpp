#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        ll N, M; cin >> N >> M;
        string S; cin >> S;
        vector<ll> R(N*M), C(N*M);
        vector<ll> cntcol(M);
        ll cntr = 0, cntc = 0;
        for(int i=0; i<N*M; ++i){
            if(cntcol[i%M]==0 && S[i]=='1'){
                cntcol[i%M] = 1;
                ++cntc;
            }
            if(i<M){
                cntr += S[i]-'0';
                R[i] = (!!cntr);
            }
            else{
                cntr += S[i]-S[i-M];
                R[i] = R[i-M] + (!!cntr);
            }
            cout << cntc+R[i] << " ";
        }
        cout << "\n";
    }
}