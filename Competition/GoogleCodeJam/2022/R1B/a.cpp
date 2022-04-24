#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        cout << "Case #" << tt << ": ";
        int N; cin >> N;
        vector<int> a(N);
        for(int i=0; i<N; ++i) cin >> a[i];
        int m=0;
        for(int i=1; i<N; ++i) m = (a[i]>a[m]?i:m);
        int s = 0, b = 0;
        for(int i=0; i<=m; ++i){
            if(a[i] < b) continue;
            ++s; b = a[i];
        }
        b = 0;
        for(int i=N-1; i>m; --i){
            if(a[i] < b) continue;
            ++s; b = a[i];
        }
        cout << s << "\n";
    }
}