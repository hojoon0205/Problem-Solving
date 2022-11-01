#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using ll = long long;

int N;
ll g[200010][2];
ll r[200010];
vector<pair<ll,ll>> backg[200010];
struct Node{
    bool isend;
    int orginal_id;
    vector<pair<ll,ll>> nex;
}pool[500010];
int Gsz;
bool chk[200010];
ll ans[200010];
map<int,set<int>> roots;

void dfs_back(int node, int Gnode, int bef, ll dist){
    if(chk[node]) return;
    chk[node] = true;
    pool[Gsz].isend = true;
    pool[Gsz].orginal_id = node;
    pool[Gnode].nex.push_back({Gsz,dist});
    ++Gsz;
    for(auto &p : backg[node]){
        if(chk[p.first] || p.first == bef) continue;
        dfs_back(p.first, Gnode, node, dist+p.second);
    }
}

int ufpar[200010];
int Find(int x){ return ufpar[x] = (ufpar[x]==x?x:Find(ufpar[x])); }
void Union(int x, int y){ x=Find(x); y=Find(y); if(x!=y) ufpar[y]=x; }

int dchk[200010];
ll cycdist[200010];
ll cyclen[200010];
int rootof[200010];
bool ufchk[200010];
pair<ll,ll> sparse[200010][20];
int dep[200010];

void dfs_for_dist(int node, int depth){
    dep[node] = depth;
    if(depth>0){
        sparse[node][0].first = g[node][0];
        sparse[node][0].second = g[node][1];
        for(int i=1; i<20; ++i){
            if(sparse[node][i-1].first < 0 || cyclen[sparse[node][i-1].first] > 0) break;
            sparse[node][i].first = sparse[sparse[node][i-1].first][i-1].first;
            sparse[node][i].second = sparse[node][i-1].second + sparse[sparse[node][i-1].first][i-1].second;
        }
    }
    for(auto &pi : backg[node]){
        int nex = pi.first;
        if(cyclen[nex] > 0) continue;
        //ll d = pi.second;
        dfs_for_dist(nex, depth+1);
    }
}

//original graph에서 u->v로 가는 경로의 길이. 만약 이어져있지 않으면 -1을 return한다.
ll get_dist(int u, int v){
    if(u==v) return 0;
    if(Find(u)!=Find(v)) return -1;
    //case 1) 둘 다 cycle에 있음
    if(cyclen[u]>0 && cyclen[v]>0){
        return (cyclen[u] + cycdist[v] - cycdist[u])%(cyclen[u]);
    }
    //case 2) 하나만 cycle에 있음 -> v여야 함
    else if(cyclen[u]>0 && cyclen[v]<=0) return -1;
    else if(cyclen[u]<=0 && cyclen[v]>0){
        // u->rootof[Find(u)]->v 순으로 가야함
        int r = rootof[Find(u)];
        ll d = (cyclen[r] + cycdist[v] - cycdist[r])%(cyclen[r]);
        for(int tt=19; tt>=0; --tt){
            if(sparse[u][tt].first < 0) continue;
            d += sparse[u][tt].second;
            u = sparse[u][tt].first;
        }
        return d;
    }
    //case 3) 둘 다 cycle에 없음
    else{
        if(dep[u] <= dep[v]) return -1;
        int difdep = dep[u]-dep[v];
        ll d=0;
        for(int tt=0; tt<=19 && (1<<tt)<=difdep; ++tt){
            if((1<<tt)&difdep){
                d += sparse[u][tt].second;
                u = sparse[u][tt].first;
            }
        }
        if(u!=v) return -1;
        return d;
    }
    return -1;
}

void dfs_final(int Gnode, ll dist){
    if(pool[Gnode].isend){
        ans[pool[Gnode].orginal_id] = dist;
        return;
    }
    for(auto &pi : pool[Gnode].nex){
        int Gnex = pi.first;
        ll d = pi.second;
        dfs_final(Gnex, dist+d);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(sparse, -1, sizeof(sparse));

    cin >> N;
    for(int i=1; i<=N; ++i) ufpar[i]=i;
    for(int i=1; i<=N; ++i){
        cin >> g[i][0] >> g[i][1];
        backg[g[i][0]].push_back({i,g[i][1]});
        Union(i, g[i][0]);
    }
    for(int i=1; i<=N; ++i) cin >> r[i];

    // dist 관련 initializing
    for(int i=1; i<=N; ++i){
        if(ufchk[Find(i)]) continue;
        ufchk[Find(i)] = true;
        ll c, d=0; cycdist[i] = 0;
        for(c=i,d=0; dchk[c]==0; d+=g[c][1],c=g[c][0]){
            ++dchk[c]; cycdist[c] = d;
        }
        ll cl = d - cycdist[c];
        int troot = -1;
        for(int nd = c; cyclen[nd]==0; nd = g[nd][0]){
            cyclen[nd] = cl;
            if(backg[nd].size()>1) troot=nd;
        }
        c = troot>0?troot:c;
        rootof[Find(i)] = c;
        dfs_for_dist(c, 0);
    }

    int M; cin >> M;
    stack<int> er;
    for(;M--;){
        int nid; cin >> nid;
        // 노드 할당
        pool[Gsz].isend = false;
        pool[Gsz].orginal_id = nid;
        int cur_Gnode = Gsz;
        ++Gsz;
        // 처음 자기 땅에서 벗어나서 이 궤도에 오르는 애들 연결하기
        //cout << nid << "start" << endl;
        dfs_back(nid, cur_Gnode, -1, 0);
        //cout << nid << "mid" << endl;
        // 이전에 등장했던 궤도들 중에 연결 가능한거 찾기
        int rnid = Find(nid);
        if(cyclen[nid] > 0 || cyclen[rnid] == 0){
            for(auto &b : roots[rnid]){
                int u = pool[b].orginal_id;
                int v = nid;
                // u -> v 로 가는 경로가 있으면 pool[cur_Gnode].nex.push_back({b,dist(u,v)}); roots.erase(b);
                ll D = get_dist(u,v);
                if(D>=0){
                    pool[cur_Gnode].nex.push_back({b,D});
                    er.push(b);
                }
            }
            while(!er.empty()){ roots[rnid].erase(er.top()); er.pop(); }
        }
        if(pool[cur_Gnode].nex.size()>0) roots[rnid].insert(cur_Gnode);
        //cout << nid << "finish" << endl << endl;
    }

    for(auto &mappair : roots){
        for(auto &Gnode : mappair.second){
            dfs_final(Gnode, 0);
        }
    }
    for(int i=1; i<=N; ++i) cout << r[i]*ans[i] << "\n";
    return 0;
}