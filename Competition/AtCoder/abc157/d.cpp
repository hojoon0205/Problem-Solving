#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100010];
vector<int> blocks[100010];
int ccsize[100010];
int cci[100100];
int ans[100010];

int n, m, k;

void dfs(int node, int ccnt){
    cci[node] = ccnt;
    ++ccsize[ccnt];
    for(auto nextt : graph[node]){
        if(cci[nextt]) continue;
        dfs(nextt, ccnt);
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=m; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int ccnt = 0;
    for(int i=1; i<=n; ++i){
        if(cci[i]) continue;
        ++ccnt;
        dfs(i, ccnt);
    }
    for(int i=1; i<=n; ++i){
        ans[i] = ccsize[cci[i]] - graph[i].size() - 1;
    }
    for(int i=1; i<=k; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        if(cci[x] == cci[y]){
            --ans[x];
            --ans[y];
        }
    }
    for(int i=1; i<=n; ++i) printf("%d ", ans[i]);
    printf("\n");
}