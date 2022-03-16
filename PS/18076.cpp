#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<string> a(N);
    for(int i=0; i<N; ++i) cin >> a[i];
    vector<vector<int>> arr(N, vector<int>(N));
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j) arr[i][j] = a[i][j]-'0';
    }
    vector<vector<int>> ans(N, vector<int>(N));
    for(int i=N-2; i>=0; --i){
        vector<int> su(N);
        for(int j=i+1; j<N; ++j){
            if(su[j]==arr[i][j]) continue;
            ans[i][j] = 1;
            for(int k=j+1; k<N; ++k) su[k] = (su[k] + arr[j][k])%10;
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j) cout << ans[i][j];
        cout << "\n";
    }
}