#include<bits/stdc++.h>
using namespace std;

#define MOD (1000000007)
#define inv2 (500000004)
#define ll long long

int sum2(int x, int y){ return (x+y)%MOD; }
int mul2(int x, int y){ return (int)(( ((ll)x) * ((ll)y) )%MOD); }
//ll mul3(ll x, ll y, ll z){ return (((x*y)%MOD)*z)%MOD; }

struct SegTree{
    typedef int T; // Change this if you need
    T id = 0; // identity element (sum:0, mul:1, ...etc)
    T initval = 0, unused = 1;

    int S;
    vector<T> tree;
    vector<T> lazy;
    T combine(T a, T b){
        // Real value, parent <- combine(child1, child2)
        return (a + b) % MOD;
    }
    T lazy_prop(T a, T b){
        // Lazy value, child <- lazy_prop(child, parent) & node <- lazy_prop(node, val)
        return mul2(a, b);
    }
    void unlazy(int idx, int nl, int nr){
        // update Real value when its lazy is applied
        tree[idx] = mul2(lazy[idx], tree[idx]);
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

struct A{
    int val;
    int idx;
};

int query[300010][2];
int index_of[600010];

int pow2[300010];
int pow2i[300010];

int main()
{
    int n, q;
    scanf("%d", &n);
    pow2[0] = pow2i[0] = 1;
    for(int i=1; i<=n; ++i){
        pow2[i]  = mul2(pow2[i-1],  2);
        pow2i[i] = mul2(pow2i[i-1], inv2);
    }
    vector<A> arr;
    vector<A> array;
    A zero_idx = {0, 0};
    array.push_back(zero_idx);
    for(int i=0; i<n; ++i){
        A tmp;
        scanf("%d", &tmp.val);
        tmp.idx = i+1;
        arr.push_back(tmp);
        array.push_back(tmp);
    }
    scanf("%d", &q);
    for(int i=1; i<=q; ++i){
        scanf("%d%d", &query[i][0], &query[i][1]);
        A tmp = {query[i][1], n+i};
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end(), [](A& a, A& b)->bool{
        return a.val < b.val;
    });
    for(int i=0; i<n+q; ++i){
        //if(arr[i].idx <= n) continue;
        index_of[arr[i].idx] = i+1;
    }

    //set segtrees & init ans
    int ans = 0;
    SegTree Pl(n+q), Mi(n+q), Cnt(n+q);
    int t = 0; int ss = 0;
    for(int i=1; i<=n+q; ++i){
        if(arr[i-1].idx > n) continue;
        Cnt.set_value(i, 1);
        ++t;
        Pl.set_value(i, mul2(pow2[t], arr[i-1].val));
        Mi.set_value(i, mul2(pow2i[t], arr[i-1].val));
        ans = sum2(ans, mul2(mul2(pow2i[t], arr[i-1].val), ss));
        ss = sum2(ss, mul2(pow2[t], arr[i-1].val));
    }
    ans = mul2(ans, inv2);
    printf("%d\n", ans);

    //for(int j=1; j<=n+q; ++j) printf("%lld ", Pl.query(j, j));
    //printf("\n\n");

    for(int i=1; i<=q; ++i){
        int D_ans = 0;
        int x = query[i][0], y = query[i][1];
        int Bef = array[x].val; int Bef_i = index_of[array[x].idx]; int Bef_cnt = Cnt.query(1, Bef_i);
        int New = y; int New_i = index_of[n+i];

        //printf("%lld %lld\n%lld %lld\n\n", Bef, Bef_i, New, New_i);

        if(Bef_i < New_i){ // new one is bigger than before one
            int PlMi1 = mul2(Pl.query(1,       Bef_i-1), Mi.query(Bef_i+1, New_i-1));
            int PlMi2 = mul2(Pl.query(Bef_i+1, New_i-1), Mi.query(New_i+1, n+q));
            int Bef_pl = mul2(pow2[Bef_cnt], Bef), Bef_mi = mul2(pow2i[Bef_cnt], Bef);
            D_ans = sum2(D_ans, MOD-mul2(Bef_pl, Mi.query(Bef_i+1, n+q)));
            D_ans = sum2(D_ans, MOD-mul2(Bef_mi, Pl.query(1,       Bef_i-1)));
            D_ans = sum2(D_ans, (MOD+MOD-PlMi1-PlMi2)%MOD);
            Cnt.set_value(Bef_i, 0);
            Pl.set_value(Bef_i, 0); Mi.set_value(Bef_i, 0);
            Pl.update(Bef_i+1, New_i-1, inv2); Mi.update(Bef_i+1, New_i-1, 2);
            PlMi1 = mul2(PlMi1, 2); PlMi2 = mul2(PlMi2, inv2);
            Cnt.set_value(New_i, 1);
            int New_cnt = Cnt.query(1, New_i);
            int New_pl = mul2(pow2[New_cnt], New), New_mi = mul2(pow2i[New_cnt], New);
            Pl.set_value(New_i, New_pl); Mi.set_value(New_i, New_mi);
            D_ans = sum2(D_ans,  mul2(New_pl, Mi.query(New_i+1, n+q)));
            D_ans = sum2(D_ans,  mul2(New_mi, Pl.query(1,       New_i-1)));
            D_ans = sum2(D_ans,  (PlMi1+PlMi2)%MOD);
        }
        else{
            int PlMi1 = mul2(Pl.query(1,       New_i-1), Mi.query(New_i+1, Bef_i-1));
            int PlMi2 = mul2(Pl.query(New_i+1, Bef_i-1), Mi.query(Bef_i+1, n+q));
            int Bef_pl = mul2(pow2[Bef_cnt], Bef), Bef_mi = mul2(pow2i[Bef_cnt], Bef);
            D_ans = sum2(D_ans, MOD-mul2(Bef_pl, Mi.query(Bef_i+1, n+q)));
            D_ans = sum2(D_ans, MOD-mul2(Bef_mi, Pl.query(1,       Bef_i-1)));
            D_ans = sum2(D_ans, (MOD+MOD-PlMi1-PlMi2)%MOD);
            Cnt.set_value(Bef_i, 0);
            Pl.set_value(Bef_i, 0); Mi.set_value(Bef_i, 0);
            Pl.update(New_i+1, Bef_i-1, 2); Mi.update(New_i+1, Bef_i-1, inv2);
            PlMi1 = mul2(PlMi1, inv2); PlMi2 = mul2(PlMi2, 2);
            Cnt.set_value(New_i, 1);
            int New_cnt = Cnt.query(1, New_i);
            int New_pl = mul2(pow2[New_cnt], New), New_mi = mul2(pow2i[New_cnt], New);
            Pl.set_value(New_i, New_pl); Mi.set_value(New_i, New_mi);
            D_ans = sum2(D_ans,  mul2(New_pl, Mi.query(New_i+1, n+q)));
            D_ans = sum2(D_ans,  mul2(New_mi, Pl.query(1,       New_i-1)));
            D_ans = sum2(D_ans,  (PlMi1+PlMi2)%MOD);
        }

        //for(int j=1; j<=n+q; ++j) printf("%lld ", Pl.query(j, j));
        //printf("\n\n");

        D_ans = mul2(D_ans, inv2);
        ans = sum2(ans, D_ans);
        printf("%d\n", ans);
        array[x].val = New; array[x].idx = n+i;
    }
}