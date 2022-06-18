#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
#define fi first
#define se second

vector<int> graph[200100];
ll ans = 0;
vector<pll> lr;
ll dfs(int node){
    ll M = lr[node-1].fi;
    ll S = 0;
    for(int nex : graph[node]){
        S += dfs(nex);
    }
    if(M>S){
        ans += 1;
        return lr[node-1].se;
    }
    else return min(S,lr[node-1].se);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        ll N; cin >> N;
        for(int i=1; i<=N; ++i) graph[i].clear();
        for(int i=2; i<=N; ++i){
            ll p; cin >> p;
            graph[p].push_back(i);
        }
        lr.clear();
        for(int i=1; i<=N; ++i){
            ll l, r;
            cin >> l >> r;
            lr.push_back({l,r});
        }
        ans = 0;
        dfs(1);
        cout << ans << "\n";
    }
}