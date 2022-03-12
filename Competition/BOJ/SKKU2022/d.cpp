#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
#define fi first
#define se second

vi graph[100010];
vi chk;

void DFS(int node){
    chk[node] = 1;
    //if(chk[node]>=2) return;
    bool danger = false;
    for(int nex : graph[node]){
        if(chk[nex]==0){
            DFS(nex);
            if(chk[nex]%2==1) danger = true;
        }
        else if(chk[nex]%2==1) danger = true;
    }
    if(!danger) chk[node] = 2;
    else chk[node] = 3;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    for(;M--;){
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
    }
    chk.resize(N+1);
    for(int i=1; i<=N; ++i){
        if(chk[i]) continue;
        DFS(i);
    }
    int ans = 0;
    for(int i=1; i<=N; ++i) ans += (chk[i]%2==0?1:0);
    cout << ans << endl;
}