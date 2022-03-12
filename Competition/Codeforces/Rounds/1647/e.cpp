#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define fi first
#define se second
const int CMAX = 1000000000;

void run(int N, vector<int> &p, vector<int> &cur, int rep){
    int nex = N+1;
    while(rep--){
        vector<int> r(N, CMAX);
        for(int i=0; i<N; ++i) r[p[i]-1] = min(r[p[i]-1], cur[i]);
        for(int i=0; i<N; ++i) if(r[i]==CMAX) r[i] = nex++;
        cur = r;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> p(n), a(n), b(n), cnt(n);
    for(int i=0; i<n; ++i){ cin >> p[i]; --p[i]; ++cnt[p[i]]; }
    int mA=0, cnoi=0;
    for(int i=0; i<n; ++i){ cin >> a[i]; mA = max(mA, a[i]); }
    for(int i=0; i<n; ++i){
        if(cnt[i]==0) ++cnoi;
    }

    int rep = (mA - n)/cnoi;
    // p**rep
    vector<int> rot(n);
    for(int i=0; i<n; ++i) rot[i] = i;
    while(rep){
        if(rep&1){
            vector<int> tmp(n);
            for(int i=0; i<n; ++i) tmp[i] = p[rot[i]];
            rot = tmp;
        }
        vector<int> tmp(n);
        for(int i=0; i<n; ++i) tmp[i] = p[p[i]];
        p = tmp; rep >>= 1;
    }
    set<int> S; for(int i=1; i<=n; ++i) S.insert(i);
    for(int i=0; i<n; ++i){
        auto it = S.lower_bound(a[rot[i]]);
        if(*it != a[rot[i]]) continue;
        b[i] = *it;
        S.erase(it);
    }
    for(int i=0; i<n; ++i){
        if(b[i] > 0) continue;
        auto it = S.lower_bound(a[rot[i]]);
        b[i] = *it;
        S.erase(it);
    }
    for(int i=0; i<n; ++i) cout << b[i] << " ";
    cout << endl;
    return 0;
}