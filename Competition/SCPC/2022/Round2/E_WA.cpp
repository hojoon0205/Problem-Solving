#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

ll DP[20][60][20];
ll cb[60][60];

ll comb(ll N, ll R){
    if(N<0 || R<0 || R>N) return 0;
    if(R==0 || R==N) return 1;
    if(cb[N][R]) return cb[N][R];
    return cb[N][R] = (comb(N-1,R-1)+comb(N-1,R))%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TT; cin >> TT;
    for(int tt=1; tt<=TT; ++tt){
        ll N, K; cin >> N >> K;
        vector<ll> A(N);
        for(int i=0; i<N; ++i) cin >> A[i];
        memset(DP, 0, sizeof(DP));
        for(int i=0; i<N; ++i){
            DP[i][0][0] = 1;
            DP[i][1][1] = A[i];
            for(int j=2; j<=K; ++j) DP[i][j][1] = (DP[i][j-1][1]*A[i])%MOD;
            for(int j=1; j<=K; ++j) DP[i][j][1] = (DP[i][j][1]+DP[i-1][j][1])%MOD;
            for(int j=K; j>=1; --j){
                for(int k=2; k<=i+1; ++k){
                    for(ll x=0,X=1; x<=j; ++x,X=(X*A[i])%MOD){
                        DP[i][j][k] += (DP[i-1][j-x][k-(!!x)]*X)%MOD*comb(j,x);
                        DP[i][j][k]%=MOD;
                    }
                    //DP[i][j][k]  += sum of DP[i-1][j-x][k-1]*(A[i]**x)
                }
            }
        }
        for(int i=0; i<N; ++i){
            cout << i << ":\n";
            for(int j=0; j<=K; ++j){
                for(int k=0; k<=N; ++k){
                    cout << DP[i][j][k] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }

        ll ans = 0;
        for(int i=1; i<=K; ++i){
            ll res = 0;
            for(ll k=1; k<=N; ++k){
                res += k*DP[N-1][i][k];
                res %= MOD;
            }
            cout << i << ": " << res << endl;
            ans ^= res;
        }
        cout << "Case #" << tt << "\n";
        cout << ans << "\n";
    }
}