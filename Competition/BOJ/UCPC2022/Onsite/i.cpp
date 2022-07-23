#include<bits/stdc++.h>
using namespace std;

vector<int> graph[1200010];
vector<int> igraph[1200010];

vector<int> tree;
vector<int> graphidx;
int gs;

void fill_tree(int node, int nl, int nr){
    if(nl>nr) return;
    tree[node] = ++gs;
    if(nl==nr){
        graphidx[nl] = gs;
        return;
    }
    int m = (nl+nr)/2;
    fill_tree(node*2, nl, m);
    fill_tree(node*2+1, m+1, nr);
    graph[tree[node*2]].push_back(tree[node]);
    graph[tree[node*2+1]].push_back(tree[node]);
    igraph[tree[node]].push_back(tree[node*2]);
    igraph[tree[node]].push_back(tree[node*2+1]);
    return;
}

void con_edge(int l, int r, int dest, int node, int nl, int nr){
    if(nl>nr) return;
    if(nr<l || r<nl) return;
    if(l<=nl && nr<=r){
        graph[tree[node]].push_back(dest);
        igraph[dest].push_back(tree[node]);
        return;
    }
    int m = (nl+nr)/2;
    con_edge(l, r, dest, node*2, nl, m);
    con_edge(l, r, dest, node*2+1, m+1, nr);
}

using pii = pair<int,int>;
vector<pii> v;
#define fi first
#define se second

vector<bool> chk;
int bcnt;
vector<int> bnum;
int sccnum;
vector<int> scc;
vector<vector<int>> sccs;
void dfs1(int node){
    chk[node] = true;
    for(auto &nex : graph[node]){
        if(chk[nex]) continue;
        dfs1(nex);
    }
    bnum[++bcnt] = node;
}
void dfs2(int node, int snum){
    chk[node] = false;
    scc[node] = snum;
    sccs[snum].push_back(node);
    for(auto &nex : igraph[node]){
        if(!chk[nex]) continue;
        dfs2(nex, snum);
    }
}

vector<vector<int>> sgraph;
vector<bool> selfloop;

vector<int> sccans;
vector<bool> updated;
void sdfs(int node, int val){
    updated[node] = true;
    sccans[node] = val;
    for(auto &nex : sgraph[node]){
        if(updated[nex]) continue;
        sdfs(nex, val);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    int S; for(S=1;S<N;S<<=1);
    tree.resize(S*2);
    graphidx.resize(N+1);
    fill_tree(1,1,N);
    v.resize(N);
    for(int i=0; i<N; ++i){
        cin >> v[i].fi;
        v[i].se = i+1;
    }
    for(int i=1; i<=N; ++i){
        int l, r; cin >> l >> r;
        con_edge(l, r, graphidx[i], 1, 1, N);
    }
    bnum.resize(gs+1);
    chk.resize(gs+1);
    for(int i=1; i<=gs; ++i){
        if(chk[i]) continue;
        dfs1(i);
    }
    scc.resize(gs+1);
    sccs.resize(gs+1);
    for(int i=gs; i>=1; --i){
        int node = bnum[i];
        if(!chk[node]) continue;
        ++sccnum;
        dfs2(node, sccnum);
    }
    sgraph.resize(sccnum+1);
    selfloop.resize(sccnum+1);
    for(int i=1; i<=gs; ++i){
        for(auto nex : graph[i]){
            if(scc[nex] == scc[i]){ selfloop[scc[i]] = true; continue; }
            sgraph[scc[i]].push_back(scc[nex]);
        }
    }
    
    sort(v.begin(), v.end(), [&](pii &x, pii &y)->bool{ return (x.fi > y.fi); });
    vector<int> ans(N+1, 0);
    sccans.resize(sccnum+1);
    updated.resize(sccnum+1);
    for(int i=0; i<N; ++i){
        int node = graphidx[v[i].se];
        int sccn = scc[node];
        if(updated[sccn]) continue;
        if(!selfloop[sccn]) continue;
        sdfs(sccn, v[i].fi);
    }
    for(int i=0; i<N; ++i){
        int idx = v[i].se;
        int node = graphidx[idx];
        int val = v[i].fi;
        int sccn = scc[node];
        if(sccans[sccn]==0) ans[idx] = val;
        else ans[idx] = sccans[sccn];
    }
    for(int i=1; i<=N; ++i) cout << ans[i] << " ";
    cout << endl;
}