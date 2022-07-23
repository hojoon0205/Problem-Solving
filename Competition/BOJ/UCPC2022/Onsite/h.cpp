#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
#define fi first
#define se second

struct A{
    ll value;
    ll cnt;
};

struct SegTree{
    vector<A> tree;
    int N, S;
    SegTree(int _N){
        N = _N;
        for(S=1;S<N;S<<=1);
        tree.resize(S*2+2, {0,0});
    }
    void update(int idx, A x){ update(idx, x, 1, 1, S); }
    void update(int idx, A x, int node, int nl, int nr){
        if(idx<nl || nr<idx) return;
        if(nl==idx && idx==nr){
            tree[node] = x;
            return;
        }
        int m = (nl+nr)/2;
        update(idx, x, node*2, nl, m);
        update(idx, x, node*2+1, m+1, nr);
        tree[node].value = tree[node*2].value + tree[node*2+1].value;
        tree[node].cnt = tree[node*2].cnt + tree[node*2+1].cnt;
    }
    ll get_Msum(ll M){ return get_Msum(M, 1, 1, S); }
    ll get_Msum(ll M, int node, int nl, int nr){
        if(nl>nr) return 0;
        if(M==0) return 0;
        if(tree[node].cnt==M) return tree[node].value;
        int m = (nl+nr)/2;
        ll ret = 0;
        if(tree[node*2+1].cnt <= M){
            ret += tree[node*2+1].value;
            ret += get_Msum(M-tree[node*2+1].cnt, node*2, nl, m);
        }
        else{
            ret += get_Msum(M, node*2+1, m+1, nr);
        }
        return ret;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, M, K; cin >> N >> M >> K;
    vector<pll> a(N);
    for(int i=0; i<N; ++i) cin >> a[i].fi >> a[i].se;
    sort(a.begin(), a.end());
    map<ll,ll> mp;
    for(int i=0; i<N; ++i){
        mp[a[i].fi] = i+1;
    }
    sort(a.begin(), a.end(), [&](pll &x, pll &y)->bool{ return x.se > y.se; });
    ll Ksum = 0;
    ll ans = 0;
    for(int i=0; i<K; ++i) Ksum += a[i].fi;
    SegTree ST(N);
    for(int i=K; i<N; ++i) ST.update(mp[a[i].fi], {a[i].fi, 1});
    ans = Ksum + ST.get_Msum(M);
    //cout << ans << endl;
    for(int i=K; i<N && M>0; ++i){
        Ksum += a[i].fi;
        --M;
        ST.update(mp[a[i].fi], {0,0});
        //ST.update(mp[a[i-K].fi], {a[i-K].fi,1});
        ll tmp = Ksum + ST.get_Msum(M);
        ans = max(ans, tmp);
        //cout << tmp << endl;
    }
    cout << ans << endl;
}