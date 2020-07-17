#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
vector<int> graph[200010];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i=1; i<=n; ++i) graph[i].clear();
        for(int i=1; i<n; ++i){
            int x, y;
            scanf("%d%d", &x, &y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        if(k==1){ printf("%d\n", n-1); continue; }
        priority_queue<pii> heap;
        vector<int> deg1(n+1);
        vector<int> deg(n+1);
        for(int i=1; i<=n; ++i){
            deg[i] = graph[i].size();
            if(graph[i].size()==1) continue;
            int c = 0;
            for(auto x : graph[i]){
                c += graph[x].size()==1?1:0;
            }
            heap.push({c, i});
            deg1[i] = c;
        }
        int ans = 0;
        while(!heap.empty()){
            auto p = heap.top();
            heap.pop();
            if(deg1[p.second] != p.first) continue;
            //printf("Case%d: %d %d\n", tt, p.first, p.second);
            if(p.first < k) break;
            ans += p.first/k;
            int d = p.first - (p.first%k);
            int node = p.second;
            deg[node] -= d;
            deg1[node] -= d;
            if(deg[node]==1){
                for(auto x : graph[node]){
                    if(deg[x]>1){
                        deg1[x] += 1;
                        heap.push({deg1[x], x});
                        break;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
}