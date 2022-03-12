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
#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;
    int N = S.length();
    map<int,pii> dp;
    dp[0] = {0,0};
    int P = 0, C = 0;
    int ans = -1;
    for(int i=0; i<N; ++i){
        P += (S[i]=='S')?2:(S[i]=='K'?-1:0);
        C += (S[i]=='S'||S[i]=='K')?1:0;
        if(dp.count(P)==0) dp[P] = {i+1,C};
        else if(C - dp[P].se > 0) ans = max(ans, i+1-dp[P].fi);
    }
    cout << ans << endl;
}