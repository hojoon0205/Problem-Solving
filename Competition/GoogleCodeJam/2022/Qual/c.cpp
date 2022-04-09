#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        cout << "Case #" << tt << ": ";
        int N; cin >> N;
        vector<int> a(N);
        for(int i=0; i<N; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        int ans = 0;
        for(int i=0; i<N; ++i){
            if(a[i] >= ans+1) ++ans;
        }
        cout << ans << "\n";
    }
}