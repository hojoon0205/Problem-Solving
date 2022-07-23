#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;
const ll MODINV3 = 332748118;
const ll MODINV2 = 499122177;
const ll emp=1e18;

struct SegTree{
    vector<ll> sum, cnt, lz;
    int base;
    SegTree(int a){
        base=1;
        while(base<a) base<<=1;
        sum.resize(base*2);
        cnt.resize(base*2);
        lz.resize(base*2,emp);
        base--;
        for(ll i=1 ; i<=a ; i++) cnt[i+base]=(i*(a-i+1))%MOD;
        for(int i=base ; i>=1 ; i--) cnt[i]=(cnt[i*2]+cnt[i*2+1])%MOD;
    }
    void pro(int ns, int nf, int num){
        if(lz[num]==emp) return;
        if(ns<nf){
            lz[num*2]=lz[num*2+1]=lz[num];
        }
        sum[num]=(lz[num]*cnt[num])%MOD; lz[num]=emp;
    }
    void updt(ll v, int st, int fn, int ns=1, int nf=-1, int num=1){
        if(nf==-1) nf=base+1;
        pro(ns,nf,num);
        if(nf<st || fn<ns) return;
        if(st<=ns && nf<=fn){
            lz[num]=v; pro(ns,nf,num);
            return;
        }
        int mid=(ns+nf)>>1;
        updt(v,st,fn,ns,mid,num*2);
        updt(v,st,fn,mid+1,nf,num*2+1);
        sum[num]=(sum[num*2]+sum[num*2+1])%MOD;
    }
    ll qry(){
        pro(1,base+1,1);
        return sum[1];
    }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, Q; cin >> N >> Q;
    ll ans = 0;
    SegTree T(N);
    for(ll i=1; i<=Q; ++i){
        ll l, r, c;
        cin >> l >> r >> c;
        T.updt(i*c%MOD,l,r);
        (ans+=T.qry())%=MOD;
    }
    cout << ans << '\n';
    return 0;
}