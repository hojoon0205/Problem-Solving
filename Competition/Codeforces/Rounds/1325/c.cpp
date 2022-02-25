#include<bits/stdc++.h>
using namespace std;

int N;
vector<pair<int,int>> graph[100010];
vector<pair<int,int>> edges;

int ans[100010];
bool chk[100010];

int x1, x2;
bool checked = false;
vector<int> path;

bool visited[100010];

void DFS(int node){
    if(checked) return;
    visited[node] = true;
    if(node == x2){
        //printf("%d\n", path.size());fflush(stdout);
        int p = 3;
        for(int i=1; i<path.size()-1; ++i){
            if(p > N-2){ ans[path[i]] = 2; chk[2] = true; }
            else{ ans[path[i]] = p; chk[p] = true; }
            ++p;
        }
        checked = true;
        return;
    }
    for(auto X : graph[node]){
        int next = X.first, edgeid = X.second;
        if(visited[next]) continue;
        path.push_back(edgeid);
        DFS(next);
        if(checked) return;
        path.pop_back();
    }
}

int main()
{
    scanf("%d", &N);
    if(N==2){ printf("0\n"); return 0;}
    for(int i=1; i<N; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        edges.push_back(make_pair(x,y));
        graph[x].push_back(make_pair(y,i-1));
        graph[y].push_back(make_pair(x,i-1));
    }
    int c = 0, t;
    for(int i=1; i<=N && c<=1; ++i){
        if(graph[i].size() > 1) continue;
        ans[graph[i][0].second] = c;
        chk[c] = true; ++c;
        if(c==1){ x1 = i; t = graph[i][0].second; }
        else if(c==2) x2 = i;
    }
    //printf("%d %d\n", x1, x2); fflush(stdout);
    DFS(x1);
    int p = 0;
    for(int i=0; i<N-1; ++i){
        if(i == t) continue;
        if(ans[i] > 0) continue;
        while(chk[p]) ++p;
        ans[i] = p; chk[p] = true;
    }
    for(int i=0; i<N-1; ++i) printf("%d\n", ans[i]);
}