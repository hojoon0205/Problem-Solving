#include<bits/stdc++.h>
using namespace std;

struct Q{
    int a, b, c, d;
};
Q q[60];
int arr[11];
int n, m, qq;
int ans;
void dfs(int idx, int val){
    if(idx>n){
        int t = 0;
        for(int i=0; i<qq; ++i){
            int a=q[i].a, b=q[i].b, c=q[i].c, d=q[i].d;
            if(arr[b]-arr[a]==c) t += d;
        }
        ans = max(ans, t);
        return;
    }
    for(int i=val; i<=m; ++i){ arr[idx]=i; dfs(idx+1, i); }
}

int main()
{
    scanf("%d%d%d", &n, &m, &qq);
    for(int i=0; i<qq; ++i){
        scanf("%d%d%d%d", &q[i].a, &q[i].b, &q[i].c, &q[i].d);
    }
    dfs(1,1);
    printf("%d\n", ans);
}