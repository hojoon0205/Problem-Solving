//SCPC 2021 1-5
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

int par[100010];
ll diff[100010];
bool CFed[100010];

//void Find(int x, vi &par, vl &diff, vector<bool> &CFed){
void Find(int x){
	if(par[x]==x) return;
	//Find(par[x], par, diff, CFed);
	Find(par[x]);
	int p = par[x];
	diff[x] += diff[p];
	CFed[x] = (CFed[x] || CFed[p]);
	par[x] = par[p];
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int T; cin >> T;
	for(int tt=1; tt<=T; ++tt){
		cout << "Case #" << tt << "\n";
		ll n, m; cin >> n >> m;
		//vector<int> par(n+1);
		for(int i=0; i<=n; ++i) par[i] = i;
		//vector<ll> diff(n+1, 0);
		for(int i=0; i<=n; ++i) diff[i] = 0;
		//vector<bool> CFed(n+1, false);
		for(int i=0; i<=n; ++i) CFed[i] = false;
		for(;m--;){
			int ty, a, b;
			cin >> ty >> a >> b;
			Find(a); Find(b);
			int aa = par[a], bb = par[b];
			if(ty==1){
				ll d; cin >> d;
				//Find(a, par, diff, CFed);
				//Find(b, par, diff, CFed);
				//int aa = par[a], bb = par[b];
				if(aa != bb){ 
					par[bb] = aa;
					diff[bb] = d + (diff[a]-diff[b]);
					if(CFed[aa] || CFed[bb]) CFed[aa] = CFed[bb] = true;
					continue;
				}
				if(diff[b] - diff[a] == d) continue;
				else CFed[aa] = true;
			}
			else{
				//Find(a, par, diff, CFed);
				//Find(b, par, diff, CFed);
				//int aa = par[a], bb = par[b];
				if(aa != bb) cout << "NC\n";
				else if(CFed[aa] || CFed[bb]) cout << "CF\n";
				else cout << diff[b]-diff[a] << "\n";
			}
		}
	}
}
