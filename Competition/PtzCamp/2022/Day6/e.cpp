#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    if(n==1){ cout << "NO\n"; return 0; }
    cout << "YES\n";
    int N = 1<<n;
    vector<vector<int>> ans(N, vector<int>(N,0));
    for(int i=0; i<N*N/2; ++i){
        int b = i&1;
        ans[i/N*2 +  b   ][i%N] = i+1;
        ans[i/N*2 + (b^1)][i%N] = N*N-i;
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j) cout << ans[i][j] << " ";
        cout << "\n";
    }
}