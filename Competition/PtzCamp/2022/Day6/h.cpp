#include<bits/stdc++.h>
using namespace std;

using ll = long long;
vector<vector<ll>> S;

int main(){
    ll n, m;
    cin >> n >> m;
    S.resize(n+1, vector<ll>(m+1));
    for(int i=1; i<=n; ++i) S[i][1] = 1;
    for(int i=1; i<=m; ++i) S[1][i] = i*(i+1)/2;
    for(int i=2; i<=n; ++i){
        for(int j=2; j<=m; ++j) S[i][j] = S[i][j-1] + j*S[i-1][j];
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j) cout << S[i][j] << " ";
        cout << endl;
    }
}