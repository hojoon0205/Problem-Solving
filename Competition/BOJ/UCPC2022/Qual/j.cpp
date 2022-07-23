#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using ll = long long;
using ull = unsigned long long;

bool chksquare(__int128_t X){
    __int128_t L=1, R=1e18, M, tmp;
    while(L<=R){
        M = (L+R)/2;
        tmp = M*M;
        if(tmp == X) return true;
        else if(tmp < X) L = M+1;
        else R = M-1;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    for(int i=0; i<N; ++i){
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B.begin(), B.end());
    for(int i=0; i<N; ++i){
        __int128_t X = (__int128_t)A[i]*(__int128_t)B[i];
        if(!chksquare(X)){ cout << "NO\n"; return 0; }
    }
    cout << "YES\n";
}