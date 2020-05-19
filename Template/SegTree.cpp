// original code from https://github.com/jh05013/PythonAlgorithms/blob/master/cpp05013/Seglazy.cpp

#include<bits/stdc++.h>
using namespace std;

//1-base
struct SegTree{
    typedef int T; // Change this if you need
    T id = 0; // identity element (sum:0, mul:1, ...etc)
    T initval = 0;

    int S;
    vector<T> tree;
    T combine(T a, T b){
        // Real value, parent <- combine(child1, child2)
        
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