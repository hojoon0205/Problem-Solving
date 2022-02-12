#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
#define a first
#define b second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        int n; cin >> n;
        vector<pii> arr(n);
        for(int i=0; i<n; ++i) cin >> arr[i].a >> arr[i].b;
        if(n==2){
            cout << "Yes\n";
            continue;
        }
        int B = 0;
        for(int i=0; i<n; ++i) B += arr[i].b;
        sort(arr.begin(), arr.end(), [&](pii &x, pii &y)->bool{ return (x.a==y.a)?(x.b>y.b):(x.a<y.a); });
        bool ans = true;
        for(int i=0; i<n-1 && ans; ++i){
            if(B - arr[i].b + arr[i].a > arr[i+1].a) ans = false;
        }
        if(ans) cout << "Yes\n";
        else cout << "No\n";
    }
}