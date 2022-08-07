#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct SegTree{
    vector<ll> tree;
    int S, N;
    SegTree(int _N){
        N = _N;
        for(S=1;S<N;S<<=1);
        tree.resize(2*S);
    }
    void update(int idx, int value){ update(idx, value, 1, 1, S); }
    void update(int idx, int value, int node, int nl, int nr){
        if(idx<nl || nr<idx) return;
        if(nl==idx && idx==nr){
            tree[node] = value;
            return;
        }
        int m = (nl+nr)/2;
        update(idx, value, node*2, nl, m);
        update(idx, value, node*2+1, m+1, nr);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    ll get_sum(int l, int r){ return get_sum(l, r, 1, 1, S); }
    ll get_sum(int l, int r, int node, int nl, int nr){
        if(r<nl || nr<l) return 0;
        if(l<=nl && nr<=r) return tree[node];
        int m = (nl+nr)/2;
        return get_sum(l, r, node*2, nl, m) + get_sum(l, r, node*2+1, m+1, nr);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        int N; cin >> N;
        vector<ll> a(N);
        vector<vector<ll>> idx(N+1, vector<ll>());
        vector<bool> chk(N);
        for(int i=0; i<N; ++i){
            cin >> a[i];
            idx[a[i]].push_back(i);
        }
        ll ans = 0;
        SegTree ST(N);
        for(int i=0; i<N; ++i){
            if(chk[i]) continue;
            int l = i, r = idx[a[i]].back();
            if(l>=r) continue;
            ans += (r-l) - ST.get_sum(l, r);
            chk[l] = chk[r] = true;
            idx[a[i]].pop_back();
            ST.update(l, 1);
            ST.update(r, 1);
        }
        cout << "Case #" << tt << "\n";
        cout << ans << "\n";
    }
}