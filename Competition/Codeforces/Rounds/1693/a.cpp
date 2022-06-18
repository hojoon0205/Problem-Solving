#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
#define fi first
#define se second
// fi : ->
// se : <-
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        ll N; cin >> N;
        vector<ll> a(N);
        for(int i=0; i<N; ++i) cin >> a[i];
        if(N==1){ cout << (a[0]==0?"Yes\n":"No\n"); continue; }
        vector<pll> cnt(N);
        cnt[0].fi = a[0];
        bool able = (a[0]>=0);
        for(int i=1; i<N; ++i){
            cnt[i].se = cnt[i-1].fi;
            cnt[i].fi = a[i] + cnt[i].se;
            if(cnt[i].fi < 0){ able = false; }
        }
        if(cnt[N-1].fi != 0) able = false;
        for(int i=N-2; i>=0; --i){
            if(cnt[i].fi==0 && cnt[i+1].fi>0) able = false;
        }
        if(!able){ cout << "No\n"; continue; }
        cout << "Yes\n";
    }
}