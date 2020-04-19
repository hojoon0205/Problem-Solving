#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> graph[200010];

int mod3[200010];
int cnt[3], c[3];
int ans[200010];

void DFS(int node, int m){
    mod3[node] = m; ++cnt[m];
    for(auto next : graph[node]){
        if(mod3[next]) continue;
        DFS(next, 3-m);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<n; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    DFS(1, 1);
    if(cnt[1] < cnt[2]){
        for(int i=1; i<=n; ++i) mod3[i] = 3-mod3[i];
        swap(cnt[1], cnt[2]);
    }
    //for(int i=1; i<=n; ++i) printf("%d ", mod3[i]);
    //printf("\n");
    c[0] = n/3;
    c[1] = (n+2)/3;
    c[2] = (n+1)/3;
    if(cnt[2] <= c[0]){
        // all 2 -> 0
        for(int i=1; i<=n; ++i){
            if(mod3[i] != 2) continue;
            --cnt[2];
            mod3[i] = 0;
            ++cnt[0];
        }
        // 1->2 or 1->0
        for(int i=1; i<=n; ++i){
            if(mod3[i] != 1) continue;
            if(cnt[0] < c[0]){
                --cnt[1];
                mod3[i] = 0;
                ++cnt[0];
            }
            else if(cnt[2] < c[2]){
                --cnt[1];
                mod3[i] = 2;
                ++cnt[2];
            }
        }
    }
    else{
        for(int i=1; i<=n; ++i){
            if(cnt[mod3[i]] > c[mod3[i]]){
                --cnt[mod3[i]];
                mod3[i] = 0;
                ++cnt[0];
            }
        }
    }
    //for(int i=1; i<=n; ++i) printf("%d ", mod3[i]);
    //printf("\n");
    int num[3] = {3, 1, 2};
    for(int i=1; i<=n; ++i){
        printf("%d ", num[mod3[i]]);
        num[mod3[i]] += 3;
    }
    printf("\n");
}