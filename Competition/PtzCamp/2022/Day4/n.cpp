#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
template <typename T>
using max_heap = priority_queue<T>;

#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, K;
    cin >> N >> K;
    map<string, ll> cur;
    map<string, ll> cnt;
    map<string, ll> cnt2;
    for(int i=0; i<N; ++i){
        string S; ll t;
        cin >> S >> t;
        cur[S] = t;
        cnt[S] = 0;
        cnt2[S] = 0;
    }
    ll l; cin >> l;
    vector<pair<string,ll>> mi(l);
    for(int i=0; i<l; ++i){
        string S; ll t;
        cin >> S >> t;
        mi[i] = {S,t};
        ++cnt[S]; ++cnt2[S];
        if(cur[S] < t){
            ll d = t - cur[S];
            cur[S] = t;
            K -= d;
        }
    }
    if(K<0){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    for(int i=0; i<l; ++i){
        if(cur[mi[i].fi] > mi[i].se){
            ans += cur[mi[i].fi];
            --cnt2[mi[i].fi];
        }
    }
    max_heap<pll> heap;
    for(auto &p : cnt){
        if(p.se == 0) continue;
        string key = p.fi;
        heap.push({cur[p.fi]*cnt2[p.fi]+p.se, 1});
        heap.push({p.se, -1});
    }
    while(K){
        pll p = heap.top(); heap.pop();
        if(p.se == -1 || K <= p.se){
            ans += p.fi * K;
            K = 0; continue;
        }
        K -= p.se;
        ans += p.fi * p.se;
    }
    cout << ans << endl;
}