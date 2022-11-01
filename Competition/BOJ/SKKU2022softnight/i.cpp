#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node{
    vector<ll> v;
};

struct MSTree{
    vector<Node> tree;
    int N, S;
    MSTree(int _N){
        N = _N;
        for(S=1;S<N;S<<=1);
        tree.resize(S*2);
    }
    void rebuild(){ rebuild(1, 1, S); }
    void rebuild(int node, int nl, int nr){
        if(nl>nr) return;
        if(nl==nr) return;
        int m = (nl+nr)/2;
        rebuild(node*2, nl, m);
        rebuild(node*2+1, m+1, nr);
        tree[node].v.clear();
        int p=0, q=0;
        auto &v1 = tree[node*2].v, &v2 = tree[node*2+1].v;
        while(p < v1.size() && q < v2.size()){
            if(v1[p] < v2[q]){
                tree[node].v.push_back(v1[p]); ++p;
            }
            else{
                tree[node].v.push_back(v2[q]); ++q;
            }
        }
        while(p < v1.size()){ tree[node].v.push_back(v1[p]); ++p; }
        while(q < v2.size()){ tree[node].v.push_back(v2[q]); ++q; }
    }
    ll query(int L, int R, ll X){ return query(L, R, X, 1, 1, S); }
    ll query(int L, int R, ll X, int node, int nl, int nr){
        if(R < nl || nr < L) return 1e18;
        if(L<=nl && nr<=R){
            auto lb = lower_bound(tree[node].v.begin(), tree[node].v.end(), X);
            ll ret = 1e18;
            if(lb != tree[node].v.end()){
                ret = min(ret, abs((*lb) - X));
                //cout << *lb << endl;
            }
            if(lb != tree[node].v.begin()){
                --lb;
                ret = min(ret, abs((*lb) - X));
                //cout << *lb << endl;
            }
            return ret;
        }
        int m = (nl+nr)/2;
        ll r1 = query(L, R, X, node*2, nl, m);
        ll r2 = query(L, R, X, node*2+1, m+1, nr);
        return min(r1,r2);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<ll> a(N+1, 0);
    for(int i=1; i<=N; ++i){ cin >> a[i]; a[i] += a[i-1]; }

    MSTree MST(N);
    for(int i=0; i<=N; ++i) MST.tree[i+MST.S].v = {2*a[i]};
    for(int i=N+1; i<MST.S; ++i) MST.tree[i+MST.S].v = {(ll)1e18};
    MST.rebuild();

    int Q; cin >> Q;
    for(;Q--;){
        int l, r; cin >> l >> r; --l;
        ll X = a[r]+a[l];
        //cout << X << endl;
        int L = (l+l+r)/3, R = (l+r+r)/3; // m in [L,R]
        //cout << L << ", " << R << endl;
        cout << MST.query(L+1, R+1, X) << "\n";
        //cout << endl;
    }
}