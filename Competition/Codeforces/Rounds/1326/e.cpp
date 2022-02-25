#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    int cnt;
    int zerocnt;
};

//1-base
struct SegTree{
    typedef Node T; // Change this if you need
    T id = {0,0,0}; // identity element (sum:0, mul:1, ...etc)
    T initval = {0,0,0};

    int S;
    vector<T> tree;
    T combine(T a, T b){
        // Real value, parent <- combine(child1, child2)
        T ret;
        ret.val = max(a.val, b.val);
        ret.cnt = a.cnt + b.cnt;
        ret.zerocnt = a.zerocnt + b.zerocnt;
        return ret;
    }

    SegTree(int N){
        for(S=1;S<N;S<<=1);
        tree.resize(S*2, initval);
    }
    void set_value(int i, T val){ set_value(i, val, 1, 1, S); }
    void set_value(int i, T val, int idx, int nl, int nr){
        if(i<nl || nr<i) return;
        if(nl==i && nr==i){
            tree[idx] = val;
            return;
        }
        int mid = (nl + nr) / 2;
        set_value(i, val, idx*2, nl, mid);
        set_value(i, val, idx*2+1, mid+1, nr);
        tree[idx] = combine(tree[idx*2], tree[idx*2+1]);
    }
    T query(int l, int r){ return query(l, r, 1, 1, S); }
    T query(int l, int r, int idx, int nl, int nr){
        if(r<nl || nr<l) return id;
        if(l<=nl && nr<=r) return tree[idx];
        int mid = (nl + nr) / 2;
        return combine( query(l, r, idx*2, nl, mid) , query(l, r, idx*2+1, mid+1, nr) );
    }
};

int main()
{
    int n;
    vector<int> p;
    scanf("%d", &n);
    vector<int> idx(n+1);
    p.push_back(0);
    for(int i=1; i<=n; ++i){
        int x;
        scanf("%d", &x);
        p.push_back(x);
        idx[x] = i;
    }
    SegTree tree(n);
    for(int i=1; i<=n; ++i){
        tree.set_value(i, {p[i],0,0});
    }
    printf("%d ", n);
    int m = 0;
    for(int t=1; t<n; ++t){
        int q;
        scanf("%d", &q);
        m = max(m, q);
        auto tq = tree.query(q, q);
        tree.set_value(q, {tq.val, 1, tq.zerocnt});
        tq = tree.query(1, q);
        if(tq.zerocnt < tq.cnt){
            int v = tq.val;
            auto tq = tree.query(idx[v], idx[v]);
            tree.set_value(idx[v], {0, tq.cnt, 1});
        }
        else{
            auto tq = tree.query(1, m);
            int v = tq.val;
            tq = tree.query(idx[v], idx[v]);
            tree.set_value(idx[v], {0, tq.cnt, 1});
        }
        printf("%d ", tree.query(1,n).val);
    }
    printf("\n");
}