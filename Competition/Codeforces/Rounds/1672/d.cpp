#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        int N; cin >> N;
        vector<int> a(N), b(N);
        for(int i=0; i<N; ++i) cin >> a[i];
        for(int i=0; i<N; ++i) cin >> b[i];
        int p=0, q=0;
        vector<int> f(N+1);
        bool sw = true;
        while(p<N && q<N){
            if(a[p]==b[q]){
                ++p; ++q;
                continue;
            }
            if(q>0 && b[q]==b[q-1] && f[b[q]]){
                --f[b[q]];
                ++q;
                continue;
            }
            else{
                ++f[a[p]];
                ++p;
            }
        }

        while(q<N){
            if(q>0 && b[q]==b[q-1] && f[b[q]]){
                --f[b[q]];
                ++q;
            }
            else{ sw = false; break; }
        }
        cout << (sw?"YES":"NO") << "\n";
    }
}