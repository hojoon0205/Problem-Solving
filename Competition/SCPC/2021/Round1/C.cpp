//SCPC 2021 1-3
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
#define pb push_back
#define mp make_pair

bool DFS(int node, vector<vi> &graph, vector<bool> &chk, int ep){
	chk[node] = true;
	for(auto &nex : graph[node]){
		if(nex == ep) return false;
		if(chk[nex]) continue;
		if(!DFS(nex, graph, chk, ep)) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//cin.tie(0);
	
	int T; cin >> T;
	for(int tt=1; tt<=T; ++tt){
		cout << "Case #" << tt << "\n";
		int n, m, k;
		cin >> n >> m >> k;
		vector<vi> graph(n, vi());
		for(int i=0; i<m; ++i){
			int x, y; cin >> x >> y;
			graph[x-1].push_back(y-1);
		}
		string ans = "";
		for(int i=0; i<k; ++i){
			int x, y; cin >> x >> y; --x; --y;
			vector<bool> chk(n); chk[x] = true;
			if(!DFS(y, graph, chk, x)){ ans += "1"; graph[y].push_back(x); }
			else{ ans += "0"; graph[x].push_back(y); }
		}
		cout << ans << "\n";
	}
}
