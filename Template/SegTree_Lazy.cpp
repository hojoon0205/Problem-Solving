// original code from https://github.com/jh05013/PythonAlgorithms/blob/master/cpp05013/Seglazy.cpp

#include<bits/stdc++.h>
using namespace std;

//1-base
struct SegTree{
    typedef int T; // Change this if you need
    T id = 0; // identity element (sum:0, mul:1, ...etc)
    T initval = 0, unused = 0;

    int S;
    vector<T> tree;
    vector<T> lazy;
    T combine(T a, T b){
        // Real value, parent <- combine(child1, child2)
        
    }
    T lazy_prop(T a, T b){
        // Lazy value, child <- lazy_prop(child, parent) & node <- lazy_prop(node, val)
        
    }
    void unlazy(int idx, int nl, int nr){
        // update Real value when its lazy is applied
        // ex) tree[idx] = lazy[idx] * (nr-nl+1)
    }

    SegTree(int N){
        for(S=1;S<N;S<<=1);
        tree.resize(S*2, initval);
        lazy.resize(S*2, unused);
    }
    void propagate(int idx, int nl, int nr){
        if(lazy[idx] == unused) return;
        if(idx < S){
            lazy[idx*2]   = lazy_prop(lazy[idx*2], lazy[idx]);
            lazy[idx*2+1] = lazy_prop(lazy[idx*2+1], lazy[idx]);
        }
        unlazy(idx, nl, nr);
        lazy[idx] = unused;
    }
    void update(int l, int r, T val){ update(l, r, val, 1, 1, S); }
    void update(int l, int r, T val, int idx, int nl, int nr){
        propagate(idx, nl, nr);
        if(r<nl || nr<l) return;
        if(l<=nl && nr<=r){
            lazy[idx] = lazy_prop(lazy[idx], val);
            propagate(idx, nl, nr);
            return;
        }
        int mid = (nl + nr) / 2;
        update(l, r, val, idx*2, nl, mid);
        update(l, r, val, idx*2+1, mid+1, nr);
        tree[idx] = combine(tree[idx*2], tree[idx*2+1]);
    }
    void set_value(int i, T val){ set_value(i, val, 1, 1, S); }
    void set_value(int i, T val, int idx, int nl, int nr){
        propagate(idx, nl, nr);
        if(i<nl || nr<i) return;
        if(nl==i && nr==i){
            tree[idx] = val;
            lazy[idx] = unused;
            propagate(idx, nl, nr);
            return;
        }
        int mid = (nl + nr) / 2;
        set_value(i, val, idx*2, nl, mid);
        set_value(i, val, idx*2+1, mid+1, nr);
        tree[idx] = combine(tree[idx*2], tree[idx*2+1]);
    }
    T query(int l, int r){ return query(l, r, 1, 1, S); }
    T query(int l, int r, int idx, int nl, int nr){
        propagate(idx, nl, nr);
        if(r<nl || nr<l) return id;
        if(l<=nl && nr<=r) return tree[idx];
        int mid = (nl + nr) / 2;
        return combine( query(l, r, idx*2, nl, mid) , query(l, r, idx*2+1, mid+1, nr) );
    }
};