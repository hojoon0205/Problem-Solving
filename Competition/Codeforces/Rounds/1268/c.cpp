#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node{
    ll count;
    ll psum;
    ll msum;
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
        ret.count = a.count + b.count;
        ret.psum = a.psum + b.psum;
        ret.msum = a.msum + b.msum;
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
    ll get_count(int l, int r){ return get_count(l, r, 1, 1, S); }
    ll get_count(int l, int r, int idx, int nl, int nr){
        if(r<nl || nr<l) return 0;
        if(l<=nl && nr<=r) return tree[idx].count;
        int mid = (nl + nr) / 2;
        return get_count(l, r, idx*2, nl, mid) + get_count(l, r, idx*2+1, mid+1, nr);
    }
    ll get_kth(int k){ return get_kth(k, 1, 1, S); }
    ll get_kth(int k, int idx, int nl, int nr){
        if(nl==nr) return tree[idx].psum;
        int mid = (nl + nr) / 2;
        if(tree[idx*2].count >= k)
            return get_kth(k, idx*2, nl, mid);
        else
            return get_kth(k-tree[idx*2].count, idx*2+1, mid+1, nr);
    }
    ll get_psum(int l, int r){ return get_psum(l, r, 1, 1, S); }
    ll get_psum(int l, int r, int idx, int nl, int nr){
        if(r<nl || nr<l) return 0;
        if(l<=nl && nr<=r) return tree[idx].psum;
        int mid = (nl + nr) / 2;
        return get_psum(l, r, idx*2, nl, mid) + get_psum(l, r, idx*2+1, mid+1, nr);
    }
    ll get_msum(int l, int r){ return get_msum(l, r, 1, 1, S); }
    ll get_msum(int l, int r, int idx, int nl, int nr){
        if(r<nl || nr<l) return 0;
        if(l<=nl && nr<=r) return tree[idx].msum;
        int mid = (nl + nr) / 2;
        return get_msum(l, r, idx*2, nl, mid) + get_msum(l, r, idx*2+1, mid+1, nr);
    }
};

ll n;
ll arr[200010];
ll idx[200010];
ll ans[200010];

int main()
{
    scanf("%lld", &n);
    SegTree st(n);
    for(int i=1; i<=n; ++i){
        scanf("%lld", &arr[i]);
        idx[arr[i]] = i;
    }

    st.set_value(idx[1], {1, idx[1], -idx[1]});
    printf("0 ");

    for(ll i=2; i<=n; ++i){
        ans[i] = ans[i-1] + st.get_count(idx[i], n);
        st.set_value(idx[i], {1, idx[i], -idx[i]});
        ll mid = st.get_kth(i/2+1);
        ll tmp = 0;
        if(i%2==0){
            tmp += mid*(i/2+1) - (i/2)*(i/2+1)/2;
            tmp -= mid*(i/2-1) + (i/2)*(i/2-1)/2;
        }
        else{
            tmp += mid*(i/2+1) - (i/2)*(i/2+1)/2;
            tmp -= mid*(i/2) + (i/2)*(i/2+1)/2;
        }
        tmp += st.get_msum(1, mid) + st.get_psum(mid+1, n);
        printf("%lld ", ans[i] + tmp);
    }
    printf("\n");
}