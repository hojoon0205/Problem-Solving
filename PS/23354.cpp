#include<bits/stdc++.h>
using namespace std;

using ll = long long;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

int N;
map<int,vector<ll>> dist;
vector<int> P;
vector<pair<int,ll>> graph[1000010];

void dijkstra(int st){
    //cout << "SETTING... " << st << endl;
    dist[st] = vector<ll>(N*N,1e18);
    vector<ll> &D = dist[st];
    min_heap<pair<ll,int>> heap;
    heap.push({0, st});
    while(!heap.empty()){
        pair<ll,int> pi = heap.top(); heap.pop();
        int cur = pi.second; ll cost = pi.first;
        if(D[cur] < cost) continue;
        for(auto &p : graph[cur]){
            int nex = p.first; ll di = p.second;
            if(D[nex] > cost + di){
                D[nex] = cost + di;
                heap.push({cost+di, nex});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int H;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            int idx = i*N+j;
            ll val; cin >> val;
            if(val==0){ P.push_back(idx); }
            if(val<0){ H = idx; val = 0; }
            vector<int> adj = {idx-N, (j)?(idx-1):(-1), (j==N-1)?(-1):(idx+1), idx+N};
            for(auto x : adj){
                if(x<0 || x>=N*N) continue;
                graph[x].push_back({idx, val});
            }
        }
    }
    //cout << "MAP SETTING START" << endl;
    if(P.size()==0){ cout << "0\n"; return 0; }
    for(int p : P) dijkstra(p);
    dijkstra(H);
    //cout << "MAP SETTING END" << endl;
    ll ans = 1e18;
    do{
        ll tmp = 0;
        tmp += dist[H][P[0]];
        for(int i=0; i<P.size()-1; ++i) tmp += dist[P[i]][P[i+1]];
        tmp += dist[P.back()][H];
        ans = min(ans, tmp);
    }while(next_permutation(P.begin(), P.end()));

    cout << ans << endl;
}