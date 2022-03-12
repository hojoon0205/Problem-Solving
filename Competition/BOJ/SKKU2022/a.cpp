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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vl A(N);
    for(int i=0; i<N; ++i) cin >> A[i];
    vl ans(N);
    ans[N-1] = -1;
    for(int i=N-2; i>=0; --i){
        if(A[i]==A[i+1]) ans[i] = ans[i+1];
        else ans[i] = i+1+1;
    }
    for(int i=0; i<N; ++i) cout << ans[i] << " ";
    cout << endl;
}