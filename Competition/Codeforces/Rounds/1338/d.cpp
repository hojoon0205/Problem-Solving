#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> graph[100010];
int id[100010];
int depth[100010];

int tree[500010], S;
int C, ans;
void update(int idx, int val){
    idx += S-1;
    tree[idx] = val; idx/=2;
    for(;idx;idx>>=1){
        tree[idx] = max(tree[idx*2],tree[idx*2+1]);
    }
}
int get_max(int l, int r){
    l += S-1; r += S-1;
    if(l>r) return 0;
    int ret = 0;
    while(l<r){
        if((l&1) == 1){ ret = max(ret, tree[l]); ++l; }
        if((r&1) == 0){ ret = max(ret, tree[r]); --r; }
        l>>=1; r>>=1;
    }
    if(l==r) ret = max(ret, tree[l]);

    return ret;
}

void dfs(int node, int prev){
    ++C; id[node] = C;
    
    int v = max(get_max(1, id[prev]-1), get_max(id[prev]+1, C-1)) + 1;
    
    ans = max(ans, v);
    update(C, v);
    
    for(auto x : graph[node]){
        if(x==prev) continue;
        dfs(x, node);
    }
}

int main()
{
    int i, j;
    scanf("%d", &n);
    for(S=1;S<n;S<<=1);
    for(int i=1; i<n; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1, 0);
    printf("%d\n", ans);
}