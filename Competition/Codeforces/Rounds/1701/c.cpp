#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        ll n, m; cin >> n >> m;
        vector<ll> a(m);
        vector<ll> ti(n, 0);
        ll mx = 0;
        for(int i=0; i<m; ++i){
            cin >> a[i];
            ++ti[a[i]-1];
            mx = max(mx, ti[a[i]-1]);
        }
        sort(ti.begin(), ti.end());
        ll ans = 0;
        for(ll l=1,r=mx; l<=r; ){
            ll mid = (l+r)/2;
            //cout << "mid: " << mid << endl;
            ll ex = 0;
            for(int i=0; i<n; ++i){
                if(ti[i] > mid) ex += ti[i] - mid;
                else if(ti[i] < mid){
                    ex -= (mid - ti[i])/2;
                }
            }
            if(ex <= 0){ ans = mid; r = mid-1; }
            else l = mid+1;
        }
        cout << ans << "\n";
    }
}