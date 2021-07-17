//SCPC 2021 1-1
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

void dfs(int node, vector<vi> &graph, vector<bool> &chk){
	chk[node] = true;
	for(auto &nex : graph[node]){
		if(chk[nex]) continue;
		dfs(nex, graph, chk);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int T; cin >> T;
	for(int tt=1; tt<=T; ++tt){
		cout << "Case #" << tt << "\n";
		int n; cin >> n;
		vi d(n);
		for(int i=0; i<n; ++i) cin >> d[i];
		vector<vi> graph(n, vi());
		for(int i=0; i<n; ++i){
			int x = i, y = i+d[i];
			if(y>=n) continue;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		vector<bool> chk(n, false);
		int cnt = 0;
		for(int i=0; i<n; ++i){
			if(chk[i]) continue;
			++cnt;
			dfs(i, graph, chk);
		}
		cout << cnt << "\n";
	}
}
