#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        int N; cin >> N;
        vector<int> a(N);
        for(int i=0; i<N; ++i) cin >> a[i];
        map<int,int> cnt;
        for(int i=0; i<N; ++i) ++cnt[a[i]];
        vector<queue<int>> qs(N+1);
        int c = 1;
        while(!cnt.empty()){
            auto it = cnt.begin();
            while(it != cnt.end()){
                auto nx = it; ++nx;
                if(nx==cnt.end()) nx = cnt.begin();
                qs[it->first].push(nx->first);
                ++it;
            }
            for(it=cnt.begin(); it!=cnt.end();){
                if(it->second <= c) cnt.erase(it++);
                else ++it;
            }
            ++c;
        }
        for(int i=0; i<N; ++i){
            cout << qs[a[i]].front() << " ";
            qs[a[i]].pop();
        }
        cout << "\n";
    }
}