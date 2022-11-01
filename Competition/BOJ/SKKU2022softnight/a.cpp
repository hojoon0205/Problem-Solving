#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, X; cin >> N >> X;
    vector<int> a(N);
    for(int i=0; i<N; ++i) cin >> a[i];
    int idx = 0;
    while(a[idx] >= X){
        ++idx; idx%=N;
        X+=1;
    }
    cout << idx+1 << endl;
}