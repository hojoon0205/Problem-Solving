#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        int N; cin >> N;
        vector<int> a(N);
        for(int i=0; i<N; ++i) cin >> a[i];
        int p;
        for(p=0; p<N; ++p){
            if(p+1 != a[p]) break;
        }
        if(p>=N){
            for(int i=0; i<N; ++i) cout << i+1 << " ";
            cout << "\n"; continue;
        }
        int q;
        for(q=p+1; q<N && p+1!=a[q]; ++q);
        for(int i=p,j=q; i<j; ++i,--j) swap(a[i],a[j]);
        for(int i=0; i<N; ++i) cout << a[i] << " ";
        cout << "\n";
    }
}