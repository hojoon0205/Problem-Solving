#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
#define fi first
#define se second

vector<vector<pii>> graph;
vector<int> a;
int M = 0;

int gcd(int x, int y){ return y?gcd(y,x%y):x; }

void dfs(int node, int val){
    a[node] = val;
    for(pii nex : graph[node]){
        if(a[nex.fi]!=-10000000){
            M = gcd(M, abs(val+nex.se-a[nex.fi]));
            continue;
        }
        dfs(nex.fi, val+nex.se);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q; cin >> N >> Q;
    graph.resize(N, vector<pii>());
    a.resize(N, -10000000);
    for(;Q--;){
        int x, y; cin >> x >> y;
        graph[x-1].push_back({y-1,1});
        graph[y-1].push_back({x-1,-1});
    }
    for(int i=0; i<N; ++i){
        if(a[i]==-10000000) dfs(i,0);
    }
    if(M==0){
        cout << N << "\n";
        for(int i=1; i<=N; ++i) cout << i << " ";
    }
    else{
        int ans = 0;
        for(int i=1; i<=M; ++i) ans += (M%i?0:1);
        cout << ans << "\n";
        for(int i=1; i<=M; ++i){
            if(M%i==0) cout << i << " ";
        }
    }
}