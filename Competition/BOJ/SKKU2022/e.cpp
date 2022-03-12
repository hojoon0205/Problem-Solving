#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
#define fi first
#define se second

struct SegTree{
    vector<double> tree, lazy;
    int N,S;
    SegTree(int _N){
        N = _N;
        for(S=1;S<N;S<<=1);
        tree.resize(S*2, 0.0);
        lazy.resize(S*2, 0.0);
    }
    void propagate(int node, int nl, int nr){
        tree[node] += lazy[node] * (nr-nl+1);
        if(node<S){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    void update(int l, int r, double val){ update(l, r, val, 1, 1, S); }
    void update(int l, int r, double val, int node, int nl, int nr){
        propagate(node, nl, nr);
        if(r<nl || nr<l) return;
        if(l<=nl && nr<=r){
            lazy[node] += val;
            propagate(node, nl, nr);
            return;
        }
        int m = (nl+nr)/2;
        update(l, r, val, node*2, nl, m);
        update(l, r, val, node*2+1, m+1, nr);
        tree[node] = tree[node*2]+tree[node*2+1];
    }
    double query(int l, int r){ return query(l, r, 1, 1, S); }
    double query(int l, int r, int node, int nl, int nr){
        propagate(node, nl, nr);
        if(r<nl || nr<l) return 0.0;
        if(l<=nl && nr<=r) return tree[node];
        int m = (nl+nr)/2;
        return query(l, r, node*2, nl, m) + query(l, r, node*2+1, m+1, nr);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll H, Q, R;
    cin >> H >> Q >> R;
    vl t(H+1);
    SegTree ST(H+1);
    for(ll i=1; i<=H; ++i) t[i] = i*(i+1)/2;
    for(;Q--;){
        ll a, b; cin >> a >> b;
        ll l=0, r=H, h;
        while(l<=r){
            ll m = (l+r)/2;
            if(t[m] < a){ h=m; l=m+1; }
            else r=m-1;
        }
        a -= t[h];
        // [a, H-h+a] add b / (H-h+1)
        ST.update(a, H-h+a, (double)b / (double)(H-h+1));
    }
    cout << fixed;
    cout.precision(12);
    for(;R--;){
        ll a, b; cin >> a >> b;
        cout << ST.query(a, b) << "\n";
    }
}