//SCPC 2021 1-4
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

int main()
{
	ios_base::sync_with_stdio(false);
	//cin.tie(0);
	
	int T; cin >> T;
	for(int tt=1; tt<=T; ++tt){
		cout << "Case #" << tt << "\n";
		ll n, m; cin >> n >> m;
		ll ans = 0, ma1=0, ma2=0, ema1=0, ema2=0;
		ll oc = 0, oans = 0, o[2];
		for(int i=0; i<n; ++i){
			ll l; cin >> l; oc += (l&1);
			vl a(l); for(auto &x : a) cin >> x;
			sort(a.begin(), a.end());
			if(l&1){
				ans += a[0]*2+a[1]+a[2]+a[3];
				oans += a[0]*2+a[1]+a[2]+a[3];
				if(oc<=2) o[oc-1] = a[2]+a[3];
			}
			else{
				ans += a[0]+a[1]+a[2]+a[3];
				oans += 2*a[0] + 2*a[1] + a[2] + a[3];
				if(ema1 < a[2]+a[3]){ ema2 = ema1; ema1 = a[2]+a[3]; }
				else if(ema2 < a[2]+a[3]){ ema2 = a[2]+a[3]; }
			}
			if(ma1 < a[2]+a[3]){ ma2 = ma1; ma1 = a[2]+a[3]; }
			else if(ma2 < a[2]+a[3]){ ma2 = a[2]+a[3]; }
		}
		if(oc!=2) cout << ans-ma1-ma2 << "\n";
		else{
			if(o[0]<o[1]){ ll tmp=o[0]; o[0]=o[1]; o[1]=tmp; }
			oans = min( min(oans-o[0]-o[1], ans-(ema1+ema2)), ans-o[0]-ema1);
			cout << oans << "\n";
		}
	}
}
