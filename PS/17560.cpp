#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;

struct STR{
    string type;
    ll b, b1;
    ll l, r, len;
    map<ll,ll> dp;
};

vector<STR> A;

ll dfs(ll idx, ll L, ll R){
    //[L,R)
    if(L==R || A[idx].len == 0) return 0;
    if(idx==0) return ((A[0].dp[R] - A[0].dp[L])%MOD + MOD)%MOD;
    if(A[idx].type == "SUB") return dfs(A[idx].b, L+A[idx].l, R+A[idx].l);
    if(R <= A[A[idx].b].len) return dfs(A[idx].b, L, R);
    if(L >= A[A[idx].b].len) return dfs(A[idx].b1, L-A[A[idx].b].len, R-A[A[idx].b].len);
    ll dpR, dpL;
    if(A[idx].dp.count(R)==0){
        A[idx].dp[R] = (dfs(A[idx].b1, 0, R-A[A[idx].b].len) + dfs(A[idx].b, 0, A[A[idx].b].len))%MOD;
    }
    dpR = A[idx].dp[R];
    if(A[idx].dp.count(L)==0){
        A[idx].dp[L] = dfs(A[idx].b, 0, L);
    }
    dpL = L==0?0:A[idx].dp[L];
    return ((dpR-dpL)%MOD+MOD)%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; string S; cin >> N >> S;
    A.resize(N);
    A[0].len = S.length();
    A[0].dp[0] = 0;
    for(ll i=0,tmp=0; i<A[0].len; ++i){
        tmp += S[i]; tmp %= MOD;
        A[0].dp[i+1] = tmp;
    }
    for(int i=1; i<N; ++i){
        cin >> A[i].type;
        if(A[i].type=="SUB"){
            cin >> A[i].b >> A[i].l >> A[i].r;
            A[i].len = A[i].r - A[i].l;
            ll b = A[i].b;
            while(A[b].type=="SUB"){
                A[i].b = A[b].b;
                A[i].l += A[b].l;
                A[i].r += A[b].l;
                b = A[i].b;
            }
        }
        else{
            cin >> A[i].b >> A[i].b1;
            A[i].len = A[A[i].b].len + A[A[i].b1].len;
        }
    }
    cout << dfs(N-1, 0, A[N-1].len) << endl;
}