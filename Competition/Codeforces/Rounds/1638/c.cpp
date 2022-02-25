#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<int>, greater<T>>;
#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        int N; cin >> N;
        vector<int> a(N+1);
        for(int i=1; i<=N; ++i) cin >> a[i];
        int p=1;
        int cnt = 0;
        while(p<=N){
            ++cnt;
            for(int x=a[p]; p<x; x=max(x,a[p])) ++p;
            ++p;
        }
        cout << cnt << "\n";
    }
}