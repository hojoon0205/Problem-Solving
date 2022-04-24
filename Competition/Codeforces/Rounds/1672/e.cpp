#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    int L = 2*N-1, R = 2000*(N+1), S;
    while(L<=R){
        int M = (L+R)/2;
        cout << "? " << M << endl;
        int li; cin >> li;
        if(li==1){ S = M; R = M-1; }
        else L = M+1;
    }
    int ans = S;
    for(int k=2; k<=N; ++k){
        cout << "? " << ((S-1)/k) << endl;
        int li; cin >> li;
        if(li==0) break;
        ans = min(ans, li*((S-1)/k));
    }
    cout << "! " << ans << endl;
}