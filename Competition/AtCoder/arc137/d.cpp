#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    vector<int> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];
    reverse(A.begin(), A.end());
    int S=1;
    for(;S<max(N,M);S<<=1);
    A.resize(S, 0);
    //for(S=1;S<M;S<<=1); M=S;
    vector<int> ANS(S);
    for(int i=1; i<S; i<<=1){
        for(int j=0; j<S; ++j){
            if(!(j&i)) continue;
            A[j] ^= A[j^i];
        }
    }
    reverse(A.begin(), A.end());
    for(int i=0; i<M; ++i) cout << A[i] << " ";
    cout << endl;
}