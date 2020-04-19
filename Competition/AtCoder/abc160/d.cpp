#include<bits/stdc++.h>
using namespace std;

int cnt[2020];

int main()
{
    int N, X, Y;
    cin >> N >> X >> Y;
    for(int i=1; i<N; ++i) cnt[i] = N-i;
    for(int i=1; i<N; ++i){
        for(int j=i+1; j<=N; ++j){
            int dist = N;
            dist = min(dist, abs(X-i)+1+abs(j-Y));
            dist = min(dist, abs(Y-i)+1+abs(j-X));
            if(j-i > dist){ --cnt[j-i]; ++cnt[dist]; }
        }
    }
    for(int i=1; i<N; ++i) cout << cnt[i] << "\n";
}