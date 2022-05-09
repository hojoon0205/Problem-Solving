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
    for(;T--;){
        ll N; cin >> N;
        vector<ll> A(N+1);
        vector<ll> B(N+1);
        for(int i=0; i<N; ++i) cin >> A[i];
        for(int i=0; i<N; ++i){
            int x; cin >> x;
            B[x] = i;
        }
        for(int i=0; i<N; ++i){
            A[i] = B[A[i]];
        }
        ll ans = 0;
        vector<bool> chk(N);
        queue<int> V;
        for(int i=1; i<=N+1-i; ++i){
            V.push(i);
            if(i < N+1-i) V.push(N+1-i);
        }
        for(int i=0; i<N; ++i){
            if(i==A[i]) continue;
            if(chk[i]) continue;
            ll l = 0, t = i;
            while(!chk[t]){
                chk[t] = true;
                ++l;
                t = A[t];
            };
            int init = V.front(), bef; V.pop();
            bef = init;
            if(l&1) --l;
            for(--l;l--;){
                int p = V.front(); 
                ans += abs(p-bef);
                bef = p; V.pop();
            }
            ans += abs(bef-init);
            //cout << ans << endl;
        }
        cout << ans << "\n";
    }
}