#include<bits/stdc++.h>
using namespace std;

struct Node{
    int count[26];
    int status; // 0: nothing,  1: increasing,  -1: decreasing
    Node& operator =(const Node &x){
        for(int i=0; i<26; ++i) count[i] = x.count[i];
        status = x.status;
        return *this;
    }
    bool operator==(const Node &x){
        for(int i=0; i<26; ++i){
            if(count[i] != x.count[i])
                return false;
        }
        return true;
    }
};

const Node ID = {{0},0};

//1-base
struct SegTree{
    typedef Node T; // Change this if you need
    T id = ID; // identity element (sum:0, mul:1, ...etc)
    T initval = ID, unused = ID;

    int S;
    vector<T> tree;
    vector<T> lazy;
    T value;
    T combine(T a, T b){
        // Real value, parent <- combine(child1, child2)
        T tmp = id;
        for(int i=0; i<26; ++i) tmp.count[i] = a.count[i] + b.count[i];
        tmp.status = 0;
        return tmp;
    }
    T lazy_prop(T a, T b){
        // Lazy value, child <- lazy_prop(child, parent) & node <- lazy_prop(node, val)
        return b;
    }
    void unlazy(int idx, int nl, int nr){
        // update Real value when its lazy is applied
        // ex) tree[idx] = lazy[idx] * (nr-nl+1)
        for(int i=0; i<26; ++i) tree[idx].count[i] = lazy[idx].count[i];
        tree[idx].status = 0;
        int st = lazy[idx].status;
        int s = (nr-nl+1)/2;
        T L = id, R = lazy[idx];
        lazy[idx] = id;
        L.status = R.status = st;
        if(st > 0){
            for(int i=0; s && i<26; ++i){
                int x = min(R.count[i], s);
                L.count[i] += x;
                R.count[i] -= x;
                s -= x;
            }
        }
        else if(st < 0){
            for(int i=25; s && i>=0; --i){
                int x = min(R.count[i], s);
                L.count[i] += x;
                R.count[i] -= x;
                s -= x;
            }
        }
        lazy[idx*2] = L;
        lazy[idx*2+1] = R;
    }

    SegTree(int N){
        for(S=1;S<N;S<<=1);
        tree.resize(S*2, initval);
        lazy.resize(S*2, unused);
    }
    void propagate(int idx, int nl, int nr){
        if(lazy[idx] == unused) return;
        if(idx < S){
            unlazy(idx, nl, nr);
        }
        else{ tree[idx] = lazy[idx]; tree[idx].status = 0; }
        lazy[idx] = unused;
    }
    void update(int l, int r, T val){ value = val; update(l, r, 1, 1, S); }
    void update(int l, int r, int idx, int nl, int nr){
        propagate(idx, nl, nr);
        if(r<nl || nr<l) return;
        if(l<=nl && nr<=r){
            T tmp = id;
            tmp.status = value.status;
            int cnt = nr-nl+1;
            if(value.status > 0){ // increasing(non-decreasing)
                for(int i=0; cnt && i<26; ++i){
                    int x = min(value.count[i], cnt);
                    tmp.count[i] += x;
                    value.count[i] -= x;
                    cnt -= x;
                }
            }
            else if(value.status < 0){ // decreasing(non-increasing)
                for(int i=25; cnt && i>=0; --i){
                    int x = min(value.count[i], cnt);
                    tmp.count[i] += x;
                    value.count[i] -= x;
                    cnt -= x;
                }
            }
            lazy[idx] = lazy_prop(lazy[idx], tmp);
            propagate(idx, nl, nr);
            return;
        }
        int mid = (nl + nr) / 2;
        update(l, r, idx*2, nl, mid);
        update(l, r, idx*2+1, mid+1, nr);
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

char str[100010];

int main()
{
    int N, Q;
    scanf("%d%d", &N, &Q);
    scanf("%s", str+1);
    SegTree seg(N);
    int S = seg.S;
    for(int i=1; i<=S; ++i){
        Node tmp = ID;
        tmp.count[i>N?0:(str[i]-'a')] = 1;
        seg.set_value(i, tmp);
    }
    for(int i=1; i<=Q; ++i){
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        Node tmp = seg.query(l, r);
        tmp.status = k*2-1;
        seg.update(l, r, tmp);
    }
    for(int i=1; i<=N; ++i){
        Node x = seg.query(i, i);
        for(int j=0; j<26; ++j){
            if(!x.count[j]) continue;
            printf("%c", j+'a'); break;
        }
    }
    printf("\n");
}