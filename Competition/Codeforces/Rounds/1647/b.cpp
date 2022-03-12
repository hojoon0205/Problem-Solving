#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define fi first
#define se second

int n, m, C;
vector<pair<pair<int,int>, pair<int,int>>> clist;
void FF(int r, int c, vector<string> &arr, vector<vector<int>> &chk){
    chk[r][c] = C;
    clist[C].fi.fi = min(clist[C].fi.fi, r);
    clist[C].fi.se = max(clist[C].fi.se, r);
    clist[C].se.fi = min(clist[C].se.fi, c);
    clist[C].se.se = max(clist[C].se.se, c);
    if(r>0   && arr[r-1][c]=='1' && chk[r-1][c]==0) FF(r-1, c, arr, chk);
    if(r<n-1 && arr[r+1][c]=='1' && chk[r+1][c]==0) FF(r+1, c, arr, chk);
    if(c>0   && arr[r][c-1]=='1' && chk[r][c-1]==0) FF(r, c-1, arr, chk);
    if(c<m-1 && arr[r][c+1]=='1' && chk[r][c+1]==0) FF(r, c+1, arr, chk);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        cin >> n >> m; C=0; clist.clear(); clist.push_back({{0,0},{0,0}});
        vector<string> arr(n);
        for(int i=0; i<n; ++i) cin >> arr[i];
        vector<vector<int>> chk(n, vector<int>(m));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(arr[i][j]=='0' || chk[i][j]!=0) continue;
                ++C;
                clist.push_back({{1000,-1},{1000,-1}});
                FF(i, j, arr, chk);
            }
        }
        bool ans = true;
        for(int x=1; x<=C && ans; ++x){
            int mir = clist[x].fi.fi, mar = clist[x].fi.se;
            int mic = clist[x].se.fi, mac = clist[x].se.se;
            for(int i=mir; i<=mar && ans; ++i){
                for(int j=mic; j<=mac && ans; ++j){
                    if(chk[i][j]!=x){ ans = false; break; }
                }
            }
        }
        cout << (ans?"YES":"NO") << "\n";
    }
}