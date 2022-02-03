#include<bits/stdc++.h>
using namespace std;

int root, ans;
vector<vector<int>> graph;

int dfs(int node, int par){
    if(graph[node].size()==1) return 1;
    int totleaf = 0;
    for(int nex : graph[node]){
        if(nex==par) continue;
        int ret = dfs(nex, node);
        totleaf += ret;
    }
    if(node==root){ if(totleaf>=2 && graph[root].size()>=3) ++ans; return 0; }
    else if(totleaf>=2){
        ++ans;
        return 0;
    }
    return totleaf;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    graph.resize(N+2, vector<int>());
    for(int i=2; i<=N; ++i){
        int p; cin >> p;
        graph[p].push_back(i);
        graph[i].push_back(p);
    }
    for(root=1; graph[root].size()<=2; ++root);
    if(root>N){ cout << "1\n"; return 0; }
    dfs(root, 0);
    cout << (ans==0?1:ans) << endl;
}