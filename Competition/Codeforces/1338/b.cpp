#include<bits/stdc++.h>
using namespace std;

int n, minf = 1;
vector<int> graph[100010];

bool dfs(int node, int prev){
    if(graph[node].size() == 1) return true;
    bool ret, sw = false;
    for(auto x : graph[node]){
        if(x == prev) continue;
        bool r = dfs(x, node);
        if(!sw){ ret = r; sw = true; }
        else{ if(ret!=r) minf = 3; }
    }
    return !ret;
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<n; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int maxf = n-1;
    for(int i=1; i<=n; ++i){
        int c = 0;
        for(auto x : graph[i]){
            if(graph[x].size() == 1) ++c;
        }
        maxf -= max(0, c-1);
    }
    for(int i=1; i<=n; ++i){
        if(graph[i].size()==1) continue;
        dfs(i, 0);
        break;
    }
    printf("%d %d\n", minf, maxf);
}