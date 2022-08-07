#include<bits/stdc++.h>
using namespace std;

int a[260][260];
using pii = pair<int,int>;

struct SegTree{
    vector<pii> tree;
    int S, N;
    void init(int _N){
        N = _N;
        for(S=1;S<N;S<<=1);
        tree.clear();
        tree.resize(2*S, {1e9,-1e9});
    }
    void update(int idx, int value){ update(idx, value, 1, 1, S); }
    void update(int idx, int value, int node, int nl, int nr){
        if(idx<nl || nr<idx) return;
        if(nl==idx && idx==nr){
            tree[node] = {value,value};
            return;
        }
        int m = (nl+nr)/2;
        update(idx, value, node*2, nl, m);
        update(idx, value, node*2+1, m+1, nr);
        tree[node].first = min(tree[node*2].first, tree[node*2+1].first);
        tree[node].second = max(tree[node*2].second, tree[node*2+1].second);
    }
    pii get_mm(int l, int r){ return get_mm(l, r, 1, 1, S); }
    pii get_mm(int l, int r, int node, int nl, int nr){
        if(r<nl || nr<l) return {1e9,-1e9};
        if(l<=nl && nr<=r) return tree[node];
        int m = (nl+nr)/2;
        pii x = get_mm(l, r, node*2, nl, m);
        pii y = get_mm(l, r, node*2+1, m+1, nr);
        return {min(x.first,y.first), max(x.second,y.second)};
    }
};

SegTree ST[260];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TT; cin >> TT;
    for(int tt=1; tt<=TT; ++tt){
        cout << "Case #" << tt << "\n";
        int N; cin >> N;
        for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) cin >> a[i][j];
        for(int col=0; col<N; ++col){
            ST[col].init(N+1);
            for(int row=0; row<N; ++row){
                ST[col].update(row+1, a[row][col]);
            }
        }
        long long ans = 0;
        for(int rs=0; rs<N; ++rs){
            for(int re=rs; re<N; ++re){
                for(int cs=0; cs<N; ++cs){
                    pii M = {1e9,-1e9};
                    for(int ce=cs; ce<N; ++ce){
                        pii tmp = ST[ce].get_mm(rs+1,re+1);
                        M.first = min(M.first, tmp.first);
                        M.second = max(M.second, tmp.second);
                        if(M.second-M.first+1 == (ce-cs+1)*(re-rs+1)) ++ans;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}