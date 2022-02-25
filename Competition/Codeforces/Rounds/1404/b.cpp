#include<bits/stdc++.h>
using namespace std;

vector<int> graph[200010];
int dist[200010];

void dfs(int node, int di){
    dist[node] = di;
    for(auto next_ : graph[node]){
        if(dist[next_]>=0) continue;
        dfs(next_, di+1);
    }
}

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n, a, b, da, db;
        scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
        for(int i=1; i<=n; ++i) graph[i].clear();
        for(int i=1; i<n; ++i){
            int x, y;
            scanf("%d%d", &x, &y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for(int i=1; i<=n; ++i) dist[i] = -1;
        dfs(a, 0);
        if(dist[b] <= da){ printf("Alice\n"); continue; }
        int d = 0;
        for(int i=1; i<=n; ++i){
            if(dist[i] > dist[d]) d = i;
        }
        for(int i=1; i<=n; ++i) dist[i] = -1;
        dfs(d, 0);
        for(int i=1; i<=n; ++i){
            if(dist[i] > dist[d]) d = i;
        }
        if(dist[d] <= 2*da){ printf("Alice\n"); continue; }
        if(2*da+1 <= db) printf("Bob\n");
        else printf("Alice\n");
    }
}