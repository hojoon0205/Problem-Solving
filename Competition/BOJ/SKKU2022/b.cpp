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

    string A, B;
    cin >> A >> B;
    vi cnt(30);
    int N = A.length(), M = B.length();
    cnt[0] = N;
    for(int i=0; i<N; ++i){
        int p;
        for(p=0;p<M && B[p]!=A[i];++p);
        if(p>=M) continue;
        ++p;
        if(cnt[p-1]>0){ --cnt[p-1]; ++cnt[p]; }
    }
    cout << cnt[M] << endl;
}