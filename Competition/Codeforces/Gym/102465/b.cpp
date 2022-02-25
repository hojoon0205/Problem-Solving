#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
#define x first
#define y second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<pii> a(N);
    for(int i=0; i<N; ++i) cin >> a[i].x >> a[i].y;

    int l = 1, r = N, m;
    int ans=1;
    while(l<=r){
        m = (l+r)/2;
        bool chk = false;
        map<int,int> X, Y;
        for(int i=0; i<m-1; ++i){
            ++X[a[i].x];
            ++Y[a[i].y];
        }
        for(int i=m-1; i<N; ++i){
            ++X[a[i].x];
            ++Y[a[i].y];
            int lef = X.rbegin()->first;
            int rig = Y.begin()->first;
            if(rig - lef + 1 >= m){
                chk = true; break;
            }
            --X[a[i-m+1].x];
            --Y[a[i-m+1].y];
            if(X[a[i-m+1].x] == 0) X.erase(a[i-m+1].x);
            if(Y[a[i-m+1].y] == 0) Y.erase(a[i-m+1].y);
        }
        if(chk){ ans = m; l = m+1; }
        else r = m-1;
    }
    cout << ans << endl;
}