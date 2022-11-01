#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
#define fi first
#define se second

int N;
vector<pii> graph[100010];
set<int> G[20];

void dfs(int node, int bit, int onoff, int bef){
    int m = (1<<bit);
    if(onoff) G[bit].insert(node);
    for(auto &p : graph[node]){
        int nex = p.fi, w = !!(p.se & m);
        if(nex==bef) continue;
        dfs(nex, bit, onoff^w, node);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int X;
    cin >> N >> X;
    for(int i=1; i<N; ++i){
        int x, y, z; cin >> x >> y >> z;
        graph[x].push_back({y,z});
        graph[y].push_back({x,z});
    }
    for(int b=0; b<20; ++b){
        dfs(1, b, 0, -1);
    }
    int ans = 20*N;
    for(int st=1; st<=N; ++st){
        int tmp = 0;
        for(int i=0; i<20; ++i){
            if(X&(1<<i)) tmp += (G[i].find(st)==G[i].end())?(N-G[i].size()):G[i].size();
            else tmp += (G[i].find(st)==G[i].end())?G[i].size():(N-G[i].size());
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}