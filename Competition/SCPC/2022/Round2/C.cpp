#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
vector<vector<pii>> graph;

vector<int> TS;
vector<int> chk;
vector<pii> DP[3];

bool DFS(int node, int K, int dep){
    chk[node] = dep;
    for(pii pnex : graph[node]){
        int nex = pnex.first;
        int ndep = dep + (pnex.second==0?1:0);
        if(K!=-1 && pnex.second==1) continue;
        if(chk[nex]>0 && chk[nex]!=ndep) return true;
        if(chk[nex]<0 || chk[nex]==ndep) continue;
        bool c = DFS(nex, K, ndep);
        if(c) return true;
    }
    chk[node] = -1;
    TS.push_back(node);
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        cout << "Case #" << tt << "\n";
        int N, M, K; cin >> N >> M >> K;
        graph.clear();
        graph.resize(3*N);
        vector<pii> elist;
        for(int i=0; i<M; ++i){
            int x, y; string c;
            cin >> x >> y >> c;
            elist.push_back({x,y});
            // A: 3*x-3, B: 3*x-2, C: 3*x-1
            if(c=="A") graph[3*x-1].push_back({3*y-3,0});
            if(c=="B") graph[3*x-3].push_back({3*y-2,0});
            if(c=="C") graph[3*x-2].push_back({3*y-1,0});
            //for(int t=1; t<=3; ++t) graph[3*x-t].push_back({3*y-t, 1});
        }
        for(auto pi : elist){
            int a = pi.first, b = pi.second;
            for(int t=1; t<=3; ++t) graph[3*a-t].push_back({3*b-t,1});
        }
        TS.clear(); chk.clear();
        chk.resize(3*N, 0);
        bool cycle = false;
        for(int i=0; i<3*N; ++i){
            if(chk[i]) continue;
            cycle = DFS(i, K, 1); 
            if(cycle) break;
        }
        if(cycle){ cout << "-1\n"; continue; }
        reverse(TS.begin(), TS.end());
        for(int i=0; i<3; ++i){ DP[i].clear(); DP[i].resize(3*N, {0, -1}); }
        int k0 = 0, k1 = 0, k2 = 0;
        queue<int> q;
        for(int i=0; i<3*N; ++i) q.push(TS[i]);
        chk.clear(); chk.resize(3*N, true);
        while(!q.empty()){
            int cur = q.front(); q.pop();
            chk[cur] = false;
            k0 = max(k0, DP[0][cur].first);
            k1 = max(k1, DP[1][cur].first);
            k2 = max(k2, DP[2][cur].first);
            for(pii pnex : graph[cur]){
                int nex = pnex.first;
                int ck = pnex.second;
                if(ck==0 || (ck==1 && K==-1)){
                    if(DP[0][nex].first < DP[0][cur].first + (ck==0?1:0)){
                        DP[0][nex].first = DP[0][cur].first + (ck==0?1:0);
                        DP[0][nex].second = DP[0][cur].second;
                        if(!chk[nex]){ q.push(nex); chk[nex]=true; }
                    }
                    if(DP[1][nex].first < DP[1][cur].first + (ck==0?1:0)){
                        DP[1][nex].first = DP[1][cur].first + (ck==0?1:0);
                        DP[1][nex].second = DP[1][cur].second;
                        if(!chk[nex]){ q.push(nex); chk[nex]=true; }
                    }
                    if(DP[2][nex].first < DP[2][cur].first + (ck==0?1:0)){
                        DP[2][nex].first = DP[2][cur].first + (ck==0?1:0);
                        DP[2][nex].second = DP[2][cur].second;
                        if(!chk[nex]){ q.push(nex); chk[nex]=true; }
                    }
                }
                else{
                    if(DP[1][nex].first < DP[0][cur].first){
                        DP[1][nex].first = DP[0][cur].first;
                        DP[1][nex].second = cur;
                        if(!chk[nex]){ q.push(nex); chk[nex]=true; }
                    }
                    if(DP[1][cur].second>=0 && DP[1][nex].first < DP[1][cur].first - DP[0][DP[1][cur].second].first){
                        DP[1][nex].first = DP[1][cur].first - DP[0][DP[1][cur].second].first;
                        DP[1][nex].second = cur;
                        if(!chk[nex]){ q.push(nex); chk[nex]=true; }
                    }
                    if(DP[2][nex].first < DP[1][cur].first){
                        DP[2][nex].first = DP[1][cur].first;
                        DP[2][nex].second = cur;
                        if(!chk[nex]){ q.push(nex); chk[nex]=true; }
                    }
                    if(DP[2][cur].second>=0 && DP[2][nex].first < DP[2][cur].first - DP[0][DP[1][DP[2][cur].second].second].first){
                        DP[2][nex].first = DP[2][cur].first - DP[0][DP[1][DP[2][cur].second].second].first;
                        DP[2][nex].second = cur;
                        if(!chk[nex]){ q.push(nex); chk[nex]=true; }
                    }
                }
            }
        }
        if(K<=0){ cout << k0 << "\n"; continue; }
        else if(K==1) cout << k1 << "\n";
        else cout << k2 << "\n";
    }
}