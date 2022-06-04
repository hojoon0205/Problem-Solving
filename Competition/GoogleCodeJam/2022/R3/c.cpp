#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
#define fi first
#define se second

string DICT = "xACDEHIJKMORST";

void dfs(int node, vector<vector<int>> &graph, vector<int> &col){
    if(col[node]) return;
    int chk = 0;
    for(int nex : graph[node]){
        chk |= (1<<col[nex]);
    }
    int c;
    for(c=1; c<=13; ++c){
        if(chk & (1<<c)) continue;
        col[node] = c; break;
    }
    if(!col[node]){
        col[node] = 14;
        return;
    }
    for(int nex : graph[node]){
        if(col[nex]) continue;
        dfs(nex, graph, col);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        int N; cin >> N;
        vector<pii> g(N+1);
        for(int i=1; i<=N; ++i) cin >> g[i].fi;
        for(int i=1; i<=N; ++i) cin >> g[i].se;
        bool impo = false;
        for(int i=1; i<=N; ++i){
            if(g[g[i].fi].fi==i || g[g[i].fi].se==i || g[g[i].se].fi==i || g[g[i].se].se==i){
                cout << "Case #" << tt << ": IMPOSSIBLE\n";
                impo = true;
                break;
            }
        }
        if(impo) continue;
        vector<vector<int>> graph(N+1);
        vector<int> col(N+1);
        for(int i=1; i<=N; ++i){
            graph[i].push_back(g[i].fi);
            graph[i].push_back(g[i].se);
            graph[g[i].fi].push_back(i);
            graph[g[i].se].push_back(i);
            graph[i].push_back(g[g[i].fi].fi);
            graph[i].push_back(g[g[i].fi].se);
            graph[i].push_back(g[g[i].se].fi);
            graph[i].push_back(g[g[i].se].se);
            graph[g[g[i].fi].fi].push_back(i);
            graph[g[g[i].fi].se].push_back(i);
            graph[g[g[i].se].fi].push_back(i);
            graph[g[g[i].se].se].push_back(i);
        }
        for(int i=1; i<=N; ++i){
            if(col[i]) continue;
            dfs(i, graph, col);
        }
        for(int i=1; i<=N; ++i){
            if(col[i]==14) impo = true;
        }
        if(impo){ cout << "Case #" << tt << ": IMPOSSIBLE\n"; continue; }
        cout << "Case #" << tt << ": ";
        string ans = "";
        for(int i=1; i<=N; ++i) ans = ans + DICT[col[i]];
        cout << ans << "\n";
    }
}