#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        int n; cin >> n;
        vl a(n), b(n);
        for(int i=0; i<n; ++i) cin >> a[i];
        for(int i=0; i<n; ++i) cin >> b[i];
        for(int i=0; i<n; ++i) if(a[i] > b[i]) swap(a[i], b[i]);
        vl d(n);
        for(int i=0; i<n; ++i) d[i] = b[i]-a[i];
        vector<vector<int>> dp(n+1, vector<int>(20010,-1));
        const int B = 10005;
        dp[0][B] = 0;
        for(int i=0; i<n; ++i){
            for(int v=0; v<20010; ++v){
                if(dp[i][v] < 0) continue;
                dp[i+1][v - d[i]] = v;
                dp[i+1][v + d[i]] = v;
            }
        }
        int D;
        for(D = 0; D<B; ++D){
            if(dp[n][B+D] >= 0) break;
            if(dp[n][B-D] >= 0) break;
        }
        D+=B;
        //cout << "founded: " << D << endl;
        for(int i=n; i>=1; --i){
            int x = dp[i][D];
            //x +- d[i-1] == D
            d[i-1] = x - D;
            D = x;
        }
        for(int i=0; i<n; ++i) if(d[i]<0) swap(a[i], b[i]);
        ll ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j) ans += (a[i]+a[j])*(a[i]+a[j]) + (b[i]+b[j])*(b[i]+b[j]);
        }
        cout << ans << "\n";
    }
}