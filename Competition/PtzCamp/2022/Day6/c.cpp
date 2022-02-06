#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

int dp[1000010][2], root;

void dfs(int node, int par, int color){
    dp[node][0] = dp[node][1] = 0;
    if(node!=root && graph[node].size()==1) return;
    for(int nex : graph[node]){
        if(nex==par) continue;
        dfs(nex, node, color^1);
        if(graph[nex].size()==1) ++dp[node][color];
        else{
            dp[node][0] += min(dp[nex][0], dp[nex][1]+1);
            dp[node][1] += min(dp[nex][1], dp[nex][0]+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    graph.resize(N+1, vector<int>());
    for(int i=1; i<N; ++i){
        int x, y; cin >> x >> y;
        --x; --y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(root=0; graph[root].size()>1; ++root);
    dfs(root, -1, 0);
    //for(int i=0; i<N; ++i) cout << dp[i][0] << " " << dp[i][1] << endl;
    cout << dp[root][0] << endl;
}