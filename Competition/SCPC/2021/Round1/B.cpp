//SCPC 2021 1-2
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
		int n, t;
		cin >> n >> t;
		string B, A;
		cin >> B; A.resize(n+t+t, '2');
		if(t+t>=n){
			A = B;
			for(int i=t; i<n; ++i) A[i] = B[i-t];
			for(int i=0; i<n-t; ++i) A[i] = B[i+t];
			cout << A << "\n";
			continue;
		}
		for(int i=0; i<t; ++i) A[i] = A[t+n+i] = '0';
		
		for(int s=0; s<t+t; ++s){
			if(s>=t){
				if(B[s]=='0') A[s] = '0';
			}
			for(int i=s; i+t+t<n+t; i+=t+t){
				if(B[i]=='0') A[i+t+t] = '0';
				else if(A[i]=='0') A[i+t+t] = '1';
			}
		}
		//cout << A << endl;
		for(int s=n+t+t-1; s>=n; --s){
			if(s<n+t){
				if(B[s-t-t]=='0') A[s] = '0';
			}
			for(int i=s; i-t-t>=t; i-=t+t){
				if(B[i-t-t]=='0') A[i-t-t] = '0';
				else if(A[i]=='0') A[i-t-t] = '1';
			}
		}
		//cout << A << endl;
		for(int i=0; i<n; ++i){
			if(B[i]=='0') continue;
			if(A[i]=='2'){
				if(A[i+t+t] == '2') A[i]='0',A[i+t+t]='1';
				else A[i] = '0' + '1' - A[i+t+t];
			}
			else if(A[i+t+t]=='2'){
				A[i+t+t] = '0' + '1' - A[i];
			}
		}
		cout << A.substr(t,n) << "\n";
	}
}
