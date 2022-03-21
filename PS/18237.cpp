#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef struct Fraction{
	ll N;//numerator
	ll D;//denominator
}frac;
bool operator < (const frac a, const ll x){ return (a.N < a.D*x) ; }
bool operator < (const frac a, const frac x){ return (a.N * x.D < a.D * x.N) ; }
bool operator == (const frac a, const ll x){ return (a.N == a.D*x) ; }
bool operator == (const frac a, const frac x){ return (a.N * x.D == a.D * x.N) ; }
bool operator <= (const frac a, const ll x){ return ((a < x) || (a == x)); }
bool operator <= (const frac a, const frac x){ return ((a < x) || (a == x)); }
bool operator > (const frac a, const ll x){ return (!(a <= x)); }
bool operator > (const frac a, const frac x){ return (!(a <= x)); }
bool operator >= (const frac a, const ll x){ return (!(a < x)); }
bool operator >= (const frac a, const frac x){ return (!(a < x)); }
typedef struct H_ARC{
	int L, R; // clockwise index
	int P;
	int nL, nR;
	int id;
	frac S;
	vector<int> ce;
	//vector<int> child;
	priority_queue<pair<frac,int>> heap;
}h_arc;

ll ans = 0;

int Find(int p, vector<int> &uf){ return uf[p] = (uf[p]==p?p:Find(uf[p],uf)); }
void Union(int p, int q, vector<int> &uf){ uf[Find(q,uf)] = Find(p,uf); } // p <- q

void AlgorithmP(vector<ll> &polygon){
	if(polygon.size() == 3){ ans += polygon[0]*polygon[1]*polygon[2]; return; }
	if(polygon.size() == 4){ ans += min(polygon[0]*polygon[1]*polygon[2]+polygon[0]*polygon[2]*polygon[3],polygon[0]*polygon[1]*polygon[3]+polygon[1]*polygon[2]*polygon[3]); return; }

	vector<h_arc> harcs;
	int N = polygon.size();
	int M = 0;//number of potential h-arcs
	//One-Sweep Algorithm
	stack<int> st;
	stack<int> harcst;
	for(int i=0; i<N; ++i){
		while(st.size()>=2 && polygon[st.top()] > polygon[i]){
			//create new h-arc, its parents are V_t-V_i and V_t_-V_t
			int P = st.top(); st.pop();
			int L = st.top();
			if(L == 0 && i == N-1) break;
			int hp1 = harcst.top(); harcst.pop();
			int hp2 = harcst.top(); harcst.pop();
			h_arc tmp;
			tmp.L = L; tmp.R = i; tmp.id = M; tmp.P = P;
			tmp.nL = tmp.nR = P;
			ll wL = polygon[L], wR = polygon[i], wP = polygon[P];
			tmp.S.N = wL*wP*wR, tmp.S.D = wL*wP+wP*wR-wL*wR;
			if(hp1==-1 && hp2==-1) ;
			else if(hp1<0 || hp2<0) tmp.ce.push_back( hp1<0?hp2:hp1 );
			else{ tmp.ce.push_back(hp1); tmp.ce.push_back(hp2); }
			harcs.push_back( tmp ); harcst.push(M);
			++M;
		}
		harcst.push(-1);
		st.push(i);
	}
	polygon.push_back(polygon[0]);
	h_arc tmph;
	tmph.L = 0, tmph.R = N, tmph.P = 0; tmph.ce.push_back(M-1); tmph.id = M;
	harcs.push_back(tmph);
	
	vector<ll> CP(N+1, 0);
	for(int i=1; i<=N; ++i) CP[i] = CP[i-1] + polygon[i]*polygon[i-1];
	vector<bool> deleted(M+1, false);
	vector<int> uf(M+1);
	for(int i=0; i<=M; ++i) uf[i]=i;
	
	for(int i=0; i<=M; ++i){
		//init for h_i
		h_arc &h_i = harcs[i];
		h_i.S.N = i<M?polygon[h_i.L]*polygon[h_i.P]*polygon[h_i.R]:polygon[0]*polygon[1]*polygon[N-1];
		h_i.S.D = polygon[h_i.L]*polygon[h_i.P]
		        + polygon[h_i.P]*polygon[h_i.R]
		        - polygon[h_i.L]*polygon[h_i.R];
		for(auto &h_ce : h_i.ce) h_i.heap.push( make_pair(harcs[h_ce].S, h_ce) );
		
		//delete h-arcs
		ll w = min(polygon[h_i.L], polygon[h_i.R]);
		int mLR = (w==polygon[h_i.L])?h_i.L:h_i.R;
		while(!h_i.heap.empty() && h_i.heap.top().first >= w){
			int hm = h_i.heap.top().second;
			deleted[hm] = true;
			h_arc &h_m = harcs[hm];
			h_i.heap.pop();
			frac tmpS = h_m.S;
			h_i.S.D += tmpS.D;
			h_i.S.N += tmpS.D*w;
			if(mLR == h_m.L){
				h_i.S.N -= w*w*polygon[h_m.nL];
				h_i.nL = h_m.nL;
			}
			if(mLR == h_m.R){
				h_i.S.N -= w*w*polygon[h_m.nR];
				h_i.nR = h_m.nR;
			}
			while(!h_m.heap.empty()){
				h_i.heap.push( h_m.heap.top() );
				h_m.heap.pop();
			}
		}
		if(i==M) break;
		//Next work
		while(!h_i.heap.empty() && h_i.S <= h_i.heap.top().first){
			int hm = h_i.heap.top().second;
			h_arc &h_m = harcs[hm];
			Union(i, hm, uf);
			h_i.heap.pop();
			frac tmpS = h_m.S;
			h_i.S.D += tmpS.D;
			h_i.S.N += tmpS.N;
			if(mLR == h_m.L){
				h_i.S.N -= w*w*polygon[h_m.nL];
				h_i.nL = h_m.nL;
			}
			if(mLR == h_m.R){
				h_i.S.N -= w*w*polygon[h_m.nR];
				h_i.nR = h_m.nR;
			}
			while(!h_m.heap.empty()){
				h_i.heap.push( h_m.heap.top() );
				h_m.heap.pop();
			}
		}
	}
	
	ans += harcs[M].S.N;
	return;
}

int main() {
	int N;
	vector<ll> W;
	ll mi = 1e6;
	scanf("%d", &N);
	if(N==1){ printf("0\n"); return 0; }
	for(int i=0; i<N; ++i){
		ll x; scanf("%lld", &x); W.push_back(x);
		mi = min(mi,x);
		scanf("%lld", &x);
		if(i==N-1){ W.push_back(x); mi = min(mi,x); }
	}
	if(N==2){ printf("%lld\n", W[0]*W[1]*W[2]); return 0; } 
	++N;
	int p;
	for(int i=0; i<N; ++i){ if(W[i]==mi){ p=i; break; } }
	for(int i=0; i<p; ++i) W.push_back(W[i]);
	W.erase(W.begin(), W.begin()+p);
	
	vector<vector<ll>> subpolys;
	//find k for w_1==w_2==...==w_k
	ll k=0;
	for(auto &x : W) if(x == mi) ++k;
	if(k >= 2) ans += mi*mi*mi*(k - 2);
	
	//make subpolygons
	if(k >= 2){
		W.push_back(mi);
		subpolys.push_back( vector<ll>(1,mi) );
		for(int i=1; i<=N; ++i){
			subpolys.back().push_back(W[i]);
			if(mi != W[i]) continue;
			if(subpolys.back().size() <= 2) subpolys.pop_back();
			subpolys.push_back( vector<ll>(1,mi) );
		}
		subpolys.pop_back();
		W.pop_back();
	}
	else subpolys.push_back(vector<ll>(W));
	
	//when k>=2, add mi*mi*sec_mi to ans & erase minimum one
	if(k >= 2){
		for(auto &sub : subpolys){
			ll sec_mi = 1e6;
			for(auto &x : sub){
				if(x == mi) continue;
				sec_mi = min(x, sec_mi);
			}
			ans += sec_mi*mi*mi;
			sub.pop_back();
		}
	}
	
	//run one-sweep algorithms for each subpolygons. then, split the subpolygons by V_1-V_i s.
	vector<vector<ll>> polygons;
	for(auto &sub : subpolys){
		stack<ll> st;
		for(int i=0; i<sub.size(); ++i){
			ll w = sub[i];
			while(st.size() >= 2 && st.top() > w) st.pop();
			if(st.size()<2 && i>1){
				polygons.back().push_back(w);
				polygons.push_back( vector<ll>(1,mi) );
			}
			st.push(w);
			if(i==0) polygons.push_back( vector<ll>() );
			polygons.back().push_back(w);
		}
		if(polygons.back().size() < 3) polygons.pop_back();
		if(st.size() <= 3) continue;
		vector<ll> tmp(polygons.back());
		polygons.pop_back();
		while(st.size() >= 3){
			polygons.push_back( vector<ll>(1, mi) );
			st.pop();
			do{
				polygons.back().push_back( tmp.back() );
				tmp.pop_back();
			}while(tmp.back() != st.top());
			polygons.back().push_back( st.top() );
		}
	}
	
	//run Algorithm P for all subpolygons
	for(auto &polygon : polygons){
		AlgorithmP(polygon);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}