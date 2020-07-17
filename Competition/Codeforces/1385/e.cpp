#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

vector<int> graph[200010];
bool chk[200010];
int order[200010], O;
bool yes;
void dfs(int node){
    chk[node] = true;
    for(auto next : graph[node]){
        if(chk[next] && !order[next]){ yes = false; return; }
        if(chk[next]) continue;
        dfs(next);
    }
    order[node] = O; --O;
}

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n, m;
        scanf("%d%d", &n, &m);
        O = n; yes = true;
        for(int i=1; i<=n; ++i){ order[i] = 0; chk[i]=false; graph[i].clear(); }
        vector<pii> remain;
        for(int i=1; i<=m; ++i){
            int ty, x, y;
            scanf("%d%d%d", &ty, &x, &y);
            if(ty==0){
                remain.push_back({x,y});
            }
            else{
                graph[x].push_back(y);
            }
        }
        for(int i=1; i<=n; ++i){
            if(!chk[i]) dfs(i);
        }
        if(!yes){
            printf("NO\n"); continue;
        }
        printf("YES\n");
        for(auto p : remain){
            if(order[p.first] < order[p.second]) graph[p.first].push_back(p.second);
            if(order[p.second] < order[p.first]) graph[p.second].push_back(p.first);
        }
        for(int i=1; i<=n; ++i){
            for(auto x : graph[i]){
                printf("%d %d\n", i, x);
            }
        }
    }
}