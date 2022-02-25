#include<bits/stdc++.h>
using namespace std;

char a[100010];
char b[100010];
vector<int> graph[30];
bool chk[30];

int ans;

void dfs(int node){
    chk[node] = true;
    ++ans;
    for(auto next : graph[node]){
        if(chk[next]) continue;
        dfs(next);
    }
}

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n;
        scanf("%d", &n);
        scanf("%s", a);
        scanf("%s", b);
        bool sw = true;
        for(int i=0; i<20; ++i) graph[i].clear();
        memset(chk, 0, sizeof(chk));
        for(int i=0; i<n; ++i){
            if(a[i] == b[i]) continue;
            if(a[i] > b[i]){
                sw = false;
                break;
            }
            graph[a[i]-'a'].push_back(b[i]-'a');
            graph[b[i]-'a'].push_back(a[i]-'a');
        }
        if(!sw){ printf("-1\n"); continue; }
        ans = 0;
        for(int i=0; i<20; ++i){
            if(chk[i]) continue;
            dfs(i);
            --ans;
        }
        printf("%d\n", ans);
    }
}