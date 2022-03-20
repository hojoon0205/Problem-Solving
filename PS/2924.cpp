#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct UF{
    int par;
    int sz;
};

UF uf[500010];

UF Find(int x){
    return uf[x] = (uf[x].par==x ? uf[x] : Find(uf[x].par)) ;
}

void Union(int x, int y){
    x = Find(x).par; y = Find(y).par;
    if(x==y) return;
    uf[x].par = y;
    uf[y].sz += uf[x].sz;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    ll A, B, C, D; cin >> A >> B >> C >> D;
    vector<int> nex(N+1);
    for(int i=1; i<=N; ++i){
        cin >> nex[i];
        uf[i].par = i;
        uf[i].sz = 1;
    }
    vector<bool> chk(N+1);
    for(int i=1; i<=N; ++i){
        if(chk[i]) continue;
        for(int p=i; !chk[p]; p=nex[p]){
            chk[p] = true;
            Union(p, i);
        }
    }
    ll T = 1;
    for(int i=C+1; i<=N-D; ++i){
        T = T * Find(i).sz / __gcd(T, (ll)Find(i).sz);
    }
    cout << (B+T-1)/T - (A+T-2)/T << endl;
}