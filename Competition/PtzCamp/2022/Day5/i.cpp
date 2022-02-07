#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
template <typename T>
using max_heap = priority_queue<T>;

#define fi first
#define se second

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
        return min(a,b);
    }
    T lazy_prop(T a, T b){
        // Lazy value, child <- lazy_prop(child, parent) & node <- lazy_prop(node, val)
        return a + b;
    }
    void unlazy(int idx, int nl, int nr){
        // update Real value when its lazy is applied
        tree[idx] += lazy[idx];
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
    void update(int l, int r, T val){
        if(l>r) return;
        update(l, r, val, 1, 1, S);
    }
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

struct Query{
    int h, l, r;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;

    vector<pii> q;
    vector<Query> qlist(M);
    for(int i=0; i<M; ++i){
        int h, l, r;
        cin >> h >> l >> r;
        qlist[i] = {h,l,r};
        q.push_back({l, h});
        q.push_back({r+1,-h});
    }
    sort(q.begin(), q.end());
    vector<pii> top2(N+1, {1,1});
    int p = 0;
    map<int,int> tmp;
    for(int i=1; i<=N; ++i){
        while(p < q.size() && q[p].fi == i){
            if(q[p].se > 0) ++tmp[q[p].se];
            else{
                --tmp[-q[p].se];
                if(!tmp[-q[p].se]) tmp.erase(-q[p].se);
            }
            ++p;
        }
        auto rit = tmp.rbegin();
        if(rit==tmp.rend()) continue;
        top2[i].fi = rit->fi;
        if(rit->se == 1) ++rit;
        if(rit==tmp.rend()) continue;
        top2[i].se = rit->fi;
    }
    //for(int i=1; i<=N; ++i) cout << top2[i].fi << " " << top2[i].se << endl;

    vector<int> cnt(N+1);
    for(int i=1; i<=N; ++i) ++cnt[top2[i].fi];
    for(int i=N-1; i>=1; --i) cnt[i] += cnt[i+1];
    SegTree ST(N+1);
    for(int i=1; i<=N; ++i) ST.update(i,i,N+1-i - cnt[i]);
    set<int> S;
    for(int i=1; i<=N; ++i) S.insert(i);
    sort(qlist.begin(), qlist.end(), [](Query &x, Query &y)->bool{ return x.h > y.h; });
    for(auto &qu : qlist){
        int h = qu.h, l = qu.l, r = qu.r;
        vector<int> temp;
        for(auto it = S.lower_bound(l); it!=S.end() && *it <= r; ++it){
            if(top2[*it].fi == h) temp.push_back(*it);
        }
        for(auto &t : temp){
            // top2[t].fi -> top2[t].se
            ST.update(top2[t].se+1, top2[t].fi, 1);
        }
        //check if it is possible
        if(ST.query(1,N) >= 0){
            cout << "YES\n";
            for(auto &t : temp) top2[t].fi = top2[t].se;
            vector<pii> ct(N);
            for(int i=1; i<=N; ++i) ct[i-1] = {-top2[i].fi, i};
            sort(ct.begin(), ct.end());
            vector<int> ans(N+1);
            for(int i=0; i<N; ++i) ans[ct[i].se] = N-i;
            for(int i=1; i<=N; ++i) cout << ans[i] << " ";
            cout << "\n";
            return 0;
        }
        for(auto &t : temp){
            S.erase(t);
            ST.update(top2[t].se+1, top2[t].fi, -1);
        }
    }
    cout << "NO\n";
}