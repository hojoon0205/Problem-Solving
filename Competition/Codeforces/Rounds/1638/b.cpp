#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        int N; cin >> N;
        vector<int> a, b;
        for(int i=0; i<N; ++i){
            int x; cin >> x;
            if(x%2) a.push_back(x);
            else b.push_back(x);
        }
        bool ans = true;
        for(int i=0,l=a.size(); i<l-1; ++i){
            if(a[i]>a[i+1]) ans = false;
        }
        for(int i=0,l=b.size(); i<l-1; ++i){
            if(b[i]>b[i+1]) ans = false;
        }
        cout << (ans?"Yes":"No") << "\n";
    }
}