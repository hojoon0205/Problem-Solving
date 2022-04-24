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
        int x, s=0; cin >> x; --N;
        vector<int> a(N);
        for(int i=0; i<N; ++i){
            int y; cin >> y;
            if(x==y){ a[i] = 1; ++s; }
            else a[i] = 0;
            x = y;
        }
        if(N==2){
            cout << max(s-1,0) << "\n";
            continue;
        }
        x = 0; a.push_back(0);
        for(int i=0; i<N-1 && s>1; ++i){
            if(a[i]==0) continue;
            s += (1-a[i+1]) - a[i] - a[i+2];
            a[i] = a[i+2] = 0;
            a[i+1] = 1;
            ++x;
        }
        cout << x << "\n";
    }
}