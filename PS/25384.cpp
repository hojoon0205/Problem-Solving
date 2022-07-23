#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

ll N;

ll dp[3010][3010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    vector<int> col(N+1);
    for(int i=1; i<=N; ++i) cin >> col[i];
    for(int i=1; i<N; ++i){
        if(col[i] == col[i+1]){
            cout << "0\n";
            return 0;
        }
    }
    dp[1][1] = 1;
    for(int i=2; i<N; ++i){
        int p;
        for(p=i-1; p>=1; --p) if(col[i+1]==col[p]) break;
        for(int a=1; a<i; ++a) dp[i][a] = (dp[a][i-1]-dp[a][p]-dp[a-1][i-1]+dp[a-1][p]+MOD+MOD)%MOD;
        for(int b=1; b<i; ++b) dp[b][i] = (dp[i-1][b]-dp[p][b]-dp[i-1][b-1]+dp[p][b-1]+MOD+MOD)%MOD;
        dp[i][i] = (dp[i-1][i-1] - dp[i-1][p] - dp[p][i-1] + dp[p][p] +MOD+MOD)%MOD;

        for(int j=1; j<i; ++j){
            dp[i][j] += dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            dp[i][j] = (dp[i][j]+MOD)%MOD;
            dp[j][i] += dp[j-1][i]+dp[j][i-1]-dp[j-1][i-1];
            dp[j][i] = (dp[j][i]+MOD)%MOD;
        }
        dp[i][i] += dp[i-1][i]+dp[i][i-1]-dp[i-1][i-1];
        dp[i][i] = (dp[i][i]+MOD)%MOD;
    }
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<N; ++j) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[N-1][N-1] << endl;
}