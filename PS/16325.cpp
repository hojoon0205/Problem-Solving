#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;

ll N, K;
ll powK[5010][5010];
vector<vector<int>> graph;

ll dfs(int node, ll col){
    ll ret = 1;
    for(auto &nex : graph[node]){
        ret *= dfs(nex, col);
        ret %= MOD;
    }
    ret *= powK[col-1][graph[node].size()];
    ret %= MOD;
    //cout << node << " " << ret << endl;
    return ret;
}

ll combi[5050][5050];
ll comb(ll N, ll R){
    if(R<0 || R>N) return 0;
    if(R==0 || R==N) return 1;
    if(combi[N][R]) return combi[N][R];
    return combi[N][R] = (comb(N-1,R-1) + comb(N-1, R))%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for(ll col=0; col<=K; ++col){
        powK[col][0] = 1;
        for(ll i=1; i<=N; ++i) powK[col][i] = (powK[col][i-1]*col)%MOD;
    }
    graph.resize(N);
    for(int i=1; i<N; ++i){
        int p; cin >> p;
        graph[p].push_back(i);
    }
    ll ans = 0;
    for(ll col=K; col>=2; --col){
        ans += col * dfs(0,col) % MOD * comb(K, col) % MOD * (((K-col+1)&1)*2-1) + MOD;
        ans %= MOD;
    }
    cout << (ans%MOD) << endl;
}