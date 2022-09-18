#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, C; cin >> N >> C;
    vector<int> x(N);
    for(int i=0; i<N; ++i) cin >> x[i];
    sort(x.begin(), x.end());
    int l, r, ans;
    l = 1, r = x[N-1]-x[0];
    while(l<=r){
        int m = (l+r)/2;
        int p = 0, cnt = 1;
        for(int i=1; i<N; ++i){
            if(x[i] - x[p] >= m){
                ++cnt; p=i;
            }
        }
        if(cnt >= C){ ans = m; l = m+1; }
        else r = m-1;
    }
    cout << ans << endl;
}