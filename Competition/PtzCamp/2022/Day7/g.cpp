#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
vector<int> a;
vector<int> b;
vector<int> A;
vector<int> B;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    a.resize(n); b.resize(m);
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<m; ++i) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int p = -1e9;
    for(int i=0; i<n; ++i){
        if(p != a[i]){
            A.push_back(1);
        }
        else ++A.back();
        p = a[i];
    }
    p = -1e9;
    for(int j=0; j<m; ++j){
        if(p != b[j]){
            B.push_back(1);
        }
        else ++B.back();
        p = b[j];
    }
    int ans = 0;
    for(auto x : A){
        for(auto y : B) ans += min(x,y);
    }
    cout << ans << endl;
}