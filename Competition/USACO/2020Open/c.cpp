#include<bits/stdc++.h>
using namespace std;

int N;
struct A{
    int x, y, idx;
};

vector<A> arr;

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        arr.push_back({x,y,0});
    }
    sort(arr.begin(), arr.end(), [&](A a, A b){ return a.x==b.x?a.y<b.y:a.x<b.x; });
    for(int i=0; i<N; ++i) arr[i].idx = i+1;
    sort(arr.begin(), arr.end(), [&](A a, A b){ return a.y==b.y?a.x<b.x:a.y<b.y; });
    int m = N+1;
    int ans = 0;
    for(int i=0; i<N; ++i){
        m = min(m, arr[i].idx);
        if(m == N-i) ++ans;
    }
    printf("%d\n", ans);
}