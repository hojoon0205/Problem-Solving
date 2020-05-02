#include<bits/stdc++.h>
using namespace std;

int n;
int a[200010];
vector<int> graph[200010];
int ans[200010];

int tree[800010], S;
void update(int idx, int val){
    idx += S-1; tree[idx] = val;
    for(idx>>=1;idx;idx>>=1){
        tree[idx] = max(tree[idx<<1], tree[(idx<<1)+1]);
    }
}
int get_max(int l, int r){
    l += S-1; r += S-1;
    int ret = 0;
    while(l<r){
        if((l&1) == 1){ ret = max(ret, tree[l]); ++l; }
        if((r&1) == 0){ ret = max(ret, tree[r]); --r; }
        l>>=1; r>>=1;
    }
    if(l==r) ret = max(ret, tree[l]);
    return ret;
}

void dfs(int node, int par, int prev_max){
    int x = get_max(1, a[node]-1);
    int prev = tree[a[node]+S-1];
    ans[node] = max(prev_max, x+1);
    update(a[node], x+1);
    for(auto nex : graph[node]){
        if(nex == par) continue;
        dfs(nex, node, ans[node]);
    }
    update(a[node], prev);
}

int main()
{
    scanf("%d", &n);
    set<int> nums;
    for(int i=1; i<=n; ++i){ scanf("%d", &a[i]); nums.insert(a[i]); }
    map<int,int> idx; int c=0;
    for(auto x : nums){ ++c; idx[x] = c; }
    for(int i=1; i<=n; ++i) a[i] = idx[a[i]];
    for(S=1;S<c;S<<=1);
    for(int i=1; i<n; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1, 0, 0);
    for(int i=1; i<=n; ++i) printf("%d\n", ans[i]);
}