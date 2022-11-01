#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
map<pii,vector<int>> T;

vector<vector<int>> vli;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K; cin >> N >> K;
    int ti = 0, x=0, y=0;
    for(int i=0; i<N; ++i){
        string S; int b;
        cin >> S >> b;
        int dx=0, dy=0;
        if(S=="E") dx=1;
        if(S=="W") dx=-1;
        if(S=="S") dy=-1;
        if(S=="N") dy=1;
        for(int i=0; i<b; ++i){
            x += dx; y += dy;
            ++ti;
            T[{x,y}].push_back(ti);
        }
    }
    for(auto &pi : T){
        if(pi.second.size()>1) vli.push_back(pi.second);
    }

    int l=1, r=1000000, ans = -1;
    while(l<=r){
        int m = (l+r)/2;
        int cnt = 0;
        for(auto &v : vli){
            int l = v.size();
            int bef = v[0];
            for(int i=1; i<l; ++i){
                if(v[i]-bef < m) continue;
                ++cnt; bef = v[i];
            }
        }
        if(cnt >= K){ ans = m; l = m+1; }
        else r = m-1;
    }
    cout << ans << endl;
}