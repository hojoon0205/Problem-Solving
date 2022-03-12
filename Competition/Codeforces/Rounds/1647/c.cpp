#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define fi first
#define se second

struct ANS{
    int sr, sc, er, ec;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        int n, m;
        cin >> n >> m;
        vector<string> arr(n);
        vector<ANS> ans;
        for(int i=0; i<n; ++i) cin >> arr[i];
        if(arr[0][0]=='1'){
            cout << "-1\n";
            continue;
        }
        for(int i=n-1; i>=1; --i){
            for(int j=0; j<m; ++j){
                if(arr[i][j]=='0') continue;
                ans.push_back({i-1, j, i, j});
            }
        }
        for(int j=m-1; j>=1; --j){
            if(arr[0][j]=='0') continue;
            ans.push_back({0, j-1, 0, j});
        }
        cout << ans.size() << "\n";
        for(auto &a : ans) cout << (a.sr+1) << " " << (a.sc+1) << " " << (a.er+1) << " " << (a.ec+1) << "\n";
    }
}