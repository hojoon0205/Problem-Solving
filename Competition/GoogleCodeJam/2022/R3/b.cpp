#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        int N, C; cin >> N >> C;
        vector<pii> A(C+1);
        for(int i=1; i<=C; ++i) cin >> A[i].fi >> A[i].se;
        vector<int> col(N);
        for(int i=0; i<N; ++i) cin >> col[i];
        int ans = 0;
        for(int st=0; st<N; ++st){
            vector<int> cnt(C+1,0);
            int ok = C;
            int sc = col[st];
            ++cnt[sc];
            if(A[sc].fi > 0) --ok;
            if(A[sc].fi == cnt[sc]) ++ok;
            if(cnt[sc] == A[sc].se+1) --ok;
            for(int ed=(st+1)%N; (ed+1)%N!=st; ed = (ed+1)%N){
                int ec = col[ed];
                ++cnt[ec];
                if(A[ec].fi > 0 && cnt[ec]==1) --ok;
                if(A[ec].fi == cnt[ec]) ++ok;
                if(cnt[ec] == A[ec].se+1) --ok;
                if(ok==C) ++ans; 
            }
        }
        cout << "Case #" << tt << ": " << ans << "\n";
    }
}