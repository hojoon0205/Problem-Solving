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

const ll MOD = 998244353;

struct SUB{
    ll bef;
    ll bsum;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N; cin >> N;
    vector<ll> ans(N+1); ans[0] = 1;
    vector<SUB> sub(30);
    for(int i=0; i<N; ++i){
        string x; ll y; cin >> x >> y;
        int c = x[0]-'a';
        sub[c].bsum += ans[i] - sub[c].bef;
        sub[c].bsum %= MOD;
        ans[i+1] = (y * sub[c].bsum)%MOD + ans[i];
        ans[i+1] %= MOD;
        sub[c].bef = ans[i+1];
    }
    cout << (ans[N]+MOD-1)%MOD << endl;
}