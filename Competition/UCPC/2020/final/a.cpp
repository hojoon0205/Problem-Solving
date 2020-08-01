#include<bits/stdc++.h>
using namespace std;

int n, s, d, ans;
vector<int> graph[100010];
int di[100010];
bool chk[100010];

int dfs(int node){
    chk[node] = true;
    for(auto nex : graph[node]){
        if(chk[nex]) continue;
        di[node] = max(di[node], dfs(nex));
    }
    di[node] += 1;
    if(di[node] > d) ++ans;
    return di[node];
}

int main()
{
    scanf("%d%d%d", &n, &s, &d);
    for(int i=1; i<n; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(s);
    printf("%d\n", ans==0?0:((ans-1)*2));
}