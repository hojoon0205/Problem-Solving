#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        ll N; cin >> N;
        int D = 2;
        vector<int> ans(N); ans[0] = 1;
        set<int> S;
        for(int i=2; i<=N; ++i) S.insert(i);
        for(int i=1; i<N; ++i){
            if(S.count(ans[i-1]*D) == 1){
                ans[i] = ans[i-1]*D;
                S.erase(ans[i]);
            }
            else{
                ans[i] = *S.begin();
                S.erase(S.begin());
            }
        }
        cout << "2\n";
        for(int i=0; i<N; ++i) cout << ans[i] << " ";
        cout << "\n";
    }
}