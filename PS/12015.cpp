#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; ++i) cin >> a[i];
    vector<int> v; v.push_back(0);
    for(int x : a){
        if(v.back() < x){
            v.push_back(x);
            continue;
        }
        int l = 0, r = v.size()-1, p;
        while(l<=r){
            int m = (l+r)/2;
            if(v[m] < x){ p = m; l = m+1; }
            else r = m-1;
        }
        v[p+1] = x;
    }
    cout << v.size()-1 << endl;
}