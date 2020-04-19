#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
long long cnt[300010];

int main()
{
    int i;
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        int x;
        scanf("%d", &x);
        v.push_back(x);
        cnt[x] += 1;
    }
    long long ans = 0;
    for(int i=1; i<=n; ++i) ans += (cnt[i]*(cnt[i]-1))/2;
    for(auto x : v){
        int t = cnt[x];
        printf("%lld\n", ans - t*(t-1)/2 + (t-1)*(t-2)/2);
    }
}