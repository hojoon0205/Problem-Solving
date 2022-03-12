#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define fi first
#define se second

struct SegTree{
    vector<int> tree, lazy;
    int N,S;
    SegTree(int _N){
        N = _N;
        for(S=1;S<N;S<<=1);
        tree.resize(S*2, 0);
        lazy.resize(S*2, 0);
    }
    void resize(int _N){
        N = _N;
        for(S=1;S<N;S<<=1);
        tree.resize(S*2, 0);
        lazy.resize(S*2, 0);
    }
    void propagate(int node, int nl, int nr){
        if(lazy[node]==0) return;
        tree[node] = (nr-nl+1) - tree[node];
        if(node<S){
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
    void update(int l, int r){ update(l, r, 1, 1, S); }
    void update(int l, int r, int node, int nl, int nr){
        propagate(node, nl, nr);
        if(r<nl || nr<l) return;
        if(l<=nl && nr<=r){
            lazy[node] ^= 1;
            propagate(node, nl, nr);
            return;
        }
        int m = (nl+nr)/2;
        update(l, r, node*2, nl, m);
        update(l, r, node*2+1, m+1, nr);
        tree[node] = tree[node*2]+tree[node*2+1];
    }
    int query(int l, int r){ return query(l, r, 1, 1, S); }
    int query(int l, int r, int node, int nl, int nr){
        propagate(node, nl, nr);
        if(r<nl || nr<l) return 0.0;
        if(l<=nl && nr<=r) return tree[node];
        int m = (nl+nr)/2;
        return query(l, r, node*2, nl, m) + query(l, r, node*2+1, m+1, nr);
    }
};

vector<SegTree> ST;

vector<int> parent;
vector<pii> graph[100010];
vector<int> Didx;
vector<pii> Range;
int Dcnt;
void DFS(int node, int par, int D){
    ++Dcnt;
    Didx[node] = Dcnt; Range[node].fi = Dcnt;
    for(int i=0; i<20; ++i){
        int k = ((D>>i)&1);
        ST[i].tree[ST[i].S+Dcnt-1] = k;
    }
    for(pii &pi : graph[node]){
        int nex = pi.fi, di = pi.se;
        if(nex==par) continue;
        parent[nex] = di;
        DFS(nex, node, D^di);
    }
    Range[node].se = Dcnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    ST.resize(20, SegTree(N));
    //for(int i=0; i<20; ++i) ST[i].resize(N);
    for(int i=1; i<N; ++i){
        int x, y, d; cin >> x >> y >> d;
        graph[x].push_back({y,d});
        graph[y].push_back({x,d});
    }
    parent.resize(N+1,0);
    Didx.resize(N+1,0);
    Range.resize(N+1,{0,0});
    DFS(1,0,0);
    for(int i=0; i<20; ++i){
        for(int t=ST[i].S-1; t>=1; --t) ST[i].tree[t] = ST[i].tree[t*2] + ST[i].tree[t*2+1];
    }

    int Q; cin >> Q;
    for(;Q--;){
        int t, x, y; cin >> t >> x >> y;
        if(t==1){
            int v = y^parent[x];
            for(int i=0; i<20; ++i){
                int k = ((v>>i)&1);
                if(k==1) ST[i].update(Range[x].fi, Range[x].se);
            }
            parent[x] = y;
        }
        else{
            ll ans = 0;
            for(int i=0; i<20; ++i){
                ll C1 = ST[i].query(Range[x].fi, Range[x].se);
                ll C2 = ST[i].query(Range[y].fi, Range[y].se);
                ll L1 = Range[x].se - Range[x].fi + 1;
                ll L2 = Range[y].se - Range[y].fi + 1;
                ans += (1LL<<i) * ( C1*(L2-C2) + C2*(L1-C1) );
            }
            cout << ans << "\n";
        }
    }

}