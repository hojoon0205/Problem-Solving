#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m;
vector<ll> arr;

int main()
{
    scanf("%lld%lld", &n, &m);
    ll s = -n;
    for(int i=1; i<=m; ++i){
        ll x;
        scanf("%lld", &x);
        arr.push_back(x);
        s += x;
    }
    if(s<0){ printf("-1\n"); return 0; }
    vector<ll> ans;
    ll b = 1;
    for(int i=0; i<m; ++i){
        ll ne = arr[i];
        if(b > n-ne+1){ printf("-1\n"); return 0; }
        ans.push_back(b);
        if(s>0){
            ll d = min(arr[i]-1, s);
            ne -= d;
            s -= d;
        }
        b += ne;
    }
    for(auto x : ans) printf("%lld ", x);
    printf("\n");
}