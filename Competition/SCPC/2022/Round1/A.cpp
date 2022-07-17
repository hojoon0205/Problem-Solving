#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        int N;
        cin >> N;
        vector<ll> pos(N);
        for(int i=0; i<N; ++i) cin >> pos[i];
        set<pll> S;
        for(int i=0; i<N; ++i){
            int x; cin >> x;
            S.insert({x, pos[i]});
        }
        int idx = 0;
        ll ans = 0;
        for(auto &p : S){
            ans += abs(pos[idx] - p.second);
            ++idx;
        }
        cout << "Case #" << tt << "\n" << ans << "\n";
    }
}