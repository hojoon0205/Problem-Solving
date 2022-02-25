#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        int N, S; cin >> N >> S;
        vector<int> X(N);
        for(int i=0; i<N; ++i) cin >> X[i];
        sort(X.begin(), X.end());
        int D, l=1, r=X[N-1]-X[0];
        while(l<=r){
            int m = (l+r)/2;
            int cnt=1, p=0;
            for(int i=1; i<N; ++i){
                if(X[i]-X[p] >= m){ p=i; ++cnt; }
            }
            if(cnt >= S){ D = m; l = m+1; }
            else r = m-1;
        }
        cout << D << "\n";
    }
}