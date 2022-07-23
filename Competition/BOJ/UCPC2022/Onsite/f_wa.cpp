#include<bits/stdc++.h>

using namespace std;

struct SegTree{
    vector<int> mx, lz;
    int base;
    SegTree(int a){
        base=1;
        while(base<a) base<<=1;
        mx.resize(base*2);
        lz.resize(base*2);
        base--;
    }
    void pro(int ns, int nf, int num){
        if(!lz[num]) return;
        if(ns<nf){
            lz[num*2]+=lz[num];
            lz[num*2+1]+=lz[num];
        }
        mx[num]+=lz[num]; lz[num]=0;
    }
    void updt(int v, int st, int fn, int ns=1, int nf=-1, int num=1){
        if(nf==-1) nf=base+1;
        pro(ns,nf,num);
        if(nf<st || fn<ns) return;
        if(st<=ns && nf<=fn){
            lz[num]+=v; pro(ns,nf,num);
            return;
        }
        int mid=ns+nf>>1;
        updt(v,st,fn,ns,mid,num*2);
        updt(v,st,fn,mid+1,nf,num*2+1);
        mx[num]=max(mx[num*2],mx[num*2+1]);
    }
    int qry(int st, int fn, int ns=1, int nf=-1, int num=1){
        if(nf==-1) nf=base+1;
        pro(ns,nf,num);
        if(nf<st || fn<ns) return 0;
        if(st<=ns && nf<=fn) return mx[num];
        int mid=ns+nf>>1;
        return max(qry(st,fn,ns,mid,num*2),qry(st,fn,mid+1,nf,num*2+1));
    }
};

int n, k, m[500005];
int D[500005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    int x=(k+1)/2;
    for(int i=n ; i>=1 ; i--){
        cin >> m[i];
    }
    set<int> S1, S2;
    map<int,int> cnt;
    int L=x+1;
    map<int,int> cnt2;
    for(int i=L ; i<=min(n,2*x-1) ; i++){
        cnt[m[i]]++;
        cnt2[m[i]]++;
    }
    vector<int> last(k+5);
    vector<int> id;
    SegTree T(n);
    for(int i=1 ; i<=n ; i++){
        if(m[i]) S1.insert(m[i]);
        if(i==1){
            T.updt(1,1,1); D[1]=1;
        }
        else{
            if(m[i]){
                if(i>=2*x) T.updt(1,last[m[i]]+1,i-1);
                else T.updt(1,last[m[i]]+1,i);
            }
            if(1<=i-x){
                D[i]=T.qry(1,i-x);
                T.updt(D[i],i,i);
            }
            else{
                D[i]=S1.size();
                T.updt(D[i],i,i);
            }
        }
        cout << D[i] << ' ';
        last[m[i]]=i;
    }

    int ans=D[n];
/*    for(int i=n-1 ; i>=x ; i--){
        if(m[i+1]) S2.insert(m[i+1]);
        ans=max(ans,D[i]+(int)S2.size());
    }*/
    cout << ans;
    return 0;
}