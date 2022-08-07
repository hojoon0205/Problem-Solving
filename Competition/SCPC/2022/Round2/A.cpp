#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        ll N, K; cin >> N >> K;
        vector<ll> v(N);
        ll ans = 0;
        multiset<ll> ms;
        ll mi = K;
        for(int i=0; i<N; ++i){
            cin >> v[i];
            mi = min(mi, v[i]);
            if(v[i] < K) ms.insert(i);
        }
        ll cnt = 0;
        while(!ms.empty()){
            ll l = *ms.begin();
            ll r = *ms.rbegin();
            //cout << l << "," << r << endl;
            ll vl = v[l], vr = v[r];
            ll value = max(vl,vr);
            ans += (r-l+1)*(K-value-cnt);
            cnt = K-value;
            while(!ms.empty() && v[*ms.begin()] >= value) ms.erase(ms.begin());
            while(!ms.empty() && v[*ms.rbegin()] >= value){
                auto it = ms.end(); --it;
                ms.erase(it);
            }
        }
        cout << "Case #" << tt << "\n";
        cout << (K-mi) << " " << ans << "\n";
    }
}