#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
#define fi first
#define se second

vector<int> close[1010];
bool child_chk[1010];
bool candy_chk[1010];
vector<pii> ans;
bool possi = false;
vector<pll> child;
vector<pll> candy;

ll get_dist(pll &a, pll &b){
    return (a.fi-b.fi)*(a.fi-b.fi) + (a.se-b.se)*(a.se-b.se);
}

void back(int num, int N){
    if(num == N){
        possi = true;
        return;
    }
    for(int ch=0; ch<N; ++ch){
        if(child_chk[ch]) continue;
        int p=0;
        while(p<=N && candy_chk[close[ch][p]]) ++p;
        if(close[ch][p]==0) continue;
        ll dist = get_dist(candy[close[ch][p]], child[ch]);
        for(int j=p; j<=N; ++j){
            int ca = close[ch][j];
            if(dist < get_dist(candy[ca], child[ch])) break;
            if(candy_chk[ca]) continue;
            ans.push_back({ch,close[ch][j]});
            child_chk[ch] = true;
            candy_chk[ca] = true;
            back(num+1, N);
            if(possi) return;
            ans.pop_back();
            child_chk[ch] = false;
            candy_chk[ca] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        int N; cin >> N;
        child.clear(); child.resize(N);
        candy.clear(); candy.resize(N+1);
        for(int i=0; i<N; ++i) cin >> child[i].fi >> child[i].se;
        for(int i=0; i<N+1; ++i) cin >> candy[i].fi >> candy[i].se;
        for(int i=0; i<N; ++i){
            close[i].clear();
            for(int j=0; j<N+1; ++j) close[i].push_back(j);
            sort(close[i].begin(), close[i].end(), [&](int &a, int &b)->bool{
                ll da = get_dist(candy[a], child[i]);
                ll db = get_dist(candy[b], child[i]);
                return da==db?a>b:da<db;
            });
        }
        memset(child_chk,0,sizeof(child_chk));
        memset(candy_chk,0,sizeof(candy_chk));
        possi = false; ans.clear();
        back(0, N);
        if(!possi){ cout << "Case #" << tt << ": IMPOSSIBLE\n"; continue; }
        else{
            cout << "Case #" << tt << ": POSSIBLE\n";
            for(int i=0; i<N; ++i) cout << ans[i].fi+1 << " " << ans[i].se+1 << "\n";
        }
    }
}