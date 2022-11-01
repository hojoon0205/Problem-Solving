#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define fi first
#define se second

struct D{
    int cost;
    int sk[5];
};

int db[5][550];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T, K; cin >> T >> K;
    for(int i=0; i<5; ++i){
        int l; cin >> l;
        for(int j=1; j<=l; ++j) cin >> db[i][j];
        for(int j=l+1; j<550; ++j) db[i][j] = db[i][j-1];
    }
    vector<D> h[3];
    for(int i=0; i<3; ++i){
        int S; cin >> S;
        h[i].resize(S+1);
        for(int j=0; j<S; ++j) cin >> h[i][j].cost;
        for(int j=0; j<S; ++j){
            for(int t=0; t<5; ++t) cin >> h[i][j].sk[t];
        }
        h[i][S].cost = 0;
        for(int j=0; j<5; ++j) h[i][S].sk[j] = 0;
    }
    int ans = 0;
    for(int i=0; i<h[0].size(); ++i){
        for(int j=0; j<h[1].size(); ++j){
            for(int k=0; k<h[2].size(); ++k){
                D tmp;
                int anstmp = 0;
                tmp.cost = h[0][i].cost + h[1][j].cost + h[2][k].cost;
                if(tmp.cost > T) continue;
                int mindec[5], maxinc[5];
                for(int tt=0; tt<5; ++tt){
                    mindec[tt] = 10000000;
                    maxinc[tt] = 0;
                    tmp.sk[tt] = h[0][i].sk[tt] + h[1][j].sk[tt] + h[2][k].sk[tt];
                    anstmp += db[tt][tmp.sk[tt]];
                    if(tmp.sk[tt]>0) mindec[tt] = db[tt][tmp.sk[tt]] - db[tt][tmp.sk[tt]-1];
                    maxinc[tt] = db[tt][tmp.sk[tt]+1] - db[tt][tmp.sk[tt]];
                }
                ans = max(ans, anstmp);
                //cout << anstmp << endl;
                if(tmp.cost + K > T) continue;
                for(int tt=0; tt<5; ++tt){
                    for(int ttt=0; ttt<5; ++ttt){
                        if(tt==ttt) continue;
                        ans = max(ans, anstmp-mindec[tt]+maxinc[ttt]);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}