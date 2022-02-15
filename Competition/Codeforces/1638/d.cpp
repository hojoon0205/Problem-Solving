#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<int>, greater<T>>;
#define fi first
#define se second

bool chk[1010][1010];
struct _ANS{
    int i, j, c;
};
vector<_ANS> ans;
int n, m;
vector<vector<int>> a;

int solve(){
    queue<_ANS> q;
    for(int i=0; i<n-1; ++i){
        for(int j=0; j<m-1; ++j){
            if(a[i][j] == a[i][j+1] && a[i][j] == a[i+1][j] && a[i][j] == a[i+1][j+1]){
                q.push({i,j,a[i][j]});
                chk[i][j] = true;
                ans.push_back({i,j,a[i][j]});
                vector<pii> tmp = {{i,j},{i+1,j},{i,j+1},{i+1,j+1}};
                for(pii p : tmp) a[p.fi][p.se] = 0;
            }
        }
    }
    while(!q.empty()){
        auto f = q.front(); q.pop();
        int r = f.i, c = f.j, col = f.c;
        a[r][c] = a[r][c+1] = a[r+1][c] = a[r+1][c+1] = 0;
        for(int i=max(r-1, 0); i<=min(r+1, n-2); ++i){
            for(int j=max(c-1, 0); j<=min(c+1, m-2); ++j){
                if(chk[i][j]) continue;
                int b = 0; bool _c = true;
                vector<pii> tmp = {{i,j},{i+1,j},{i,j+1},{i+1,j+1}};
                for(pii p : tmp){
                    if(a[p.fi][p.se]!=0 && b!=0 && a[p.fi][p.se]!=b) _c = false;
                    else if(a[p.fi][p.se]) b = a[p.fi][p.se];
                }
                if(_c){
                    if(!b) b = 1;
                    q.push({i,j,b});
                    ans.push_back({i,j,b});
                    for(pii p : tmp) a[p.fi][p.se] = 0;
                    chk[i][j] = true;
                }
            }
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(a[i][j]) return -1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    a.clear(); a.resize(n, vector<int>(m));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j) cin >> a[i][j];
    }
    memset(chk, 0, sizeof(chk));
    int ret = solve();
    if(ret<0){ cout << "-1\n"; return 0; }
    cout << ans.size() << "\n";
    for(auto it=ans.rbegin(); it!=ans.rend(); ++it) cout << (it->i + 1) << " " << (it->j + 1) << " " << (it->c) << "\n";
}