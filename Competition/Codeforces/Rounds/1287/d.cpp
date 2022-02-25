#include<bits/stdc++.h>
using namespace std;
int n, arr[2020], par[2020], c[2020], nc, a[2020], cn, ord[2020];
vector<int> graph[2020];
bool DFS(int node){
    if(node!=0){
        ++cn;
        ord[node] = cn;
        if(c[node] > nc) return true;
        a[node] = arr[c[node]]; --nc;
        for(int i=c[node]; i<=nc; ++i)
            arr[i] = arr[i+1];
    }
    bool ret = false;
    for(auto next : graph[node]){
        ret |= DFS(next);
    }
    ret |= (c[node] > cn - ord[node] + 1);
    return ret;
}
int main()
{
    int i;
    scanf("%d", &n);
    nc = n; cn = 0;
    for(int i=1; i<=n; ++i){
        arr[i] = i;
        scanf("%d%d", &par[i], &c[i]);
        graph[par[i]].push_back(i);
        ++c[i];
    }
    bool tmp = DFS(0);
    if(tmp){ printf("NO\n"); return 0; }
    printf("YES\n");
    for(int i=1; i<=n; ++i) printf("%d ", a[i]);
    printf("\n");
}