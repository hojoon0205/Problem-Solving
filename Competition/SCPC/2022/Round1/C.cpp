#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        int N; cin >> N;
        map<ll, vector<ll>> X, Y;
        for(int i=0; i<N; ++i){
            ll x, y;
            cin >> x >> y;
            X[x].push_back(y);
            Y[y].push_back(x);
        }
        if(N%2){
            ll xx=-1, yy=-1;
            for(auto &p : X) xx = p.se.size()%2?p.fi:xx;
            for(auto &p : Y) yy = p.se.size()%2?p.fi:yy;
            //cout << "error point: (" << xx << ", " << yy << ")" << endl;
            int szx = X[xx].size(), px;
            int szy = Y[yy].size(), py;
            for(px=0; px<szx; ++px) if(X[xx][px]==yy) break;
            for(py=0; py<szy; ++py) if(Y[yy][py]==xx) break; 
            X[xx].erase(X[xx].begin()+px);
            Y[yy].erase(Y[yy].begin()+py);
        }
        for(auto &p : X) sort(p.se.begin(), p.se.end());
        for(auto &p : Y) sort(p.se.begin(), p.se.end());
        ll ans = 0;
        for(auto &p : X){
            ll t = -1;
            for(auto &y : p.se){
                ans += t*y;
                t *= -1;
            }
        }
        for(auto &p : Y){
            ll t = -1;
            for(auto &x : p.se){
                ans += t*x;
                t *= -1;
            }
        }
        cout << "Case #" << tt << "\n";
        cout << ans << "\n";
    }
}