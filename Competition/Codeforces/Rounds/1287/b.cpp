#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
char str[30];
ll arr[1510];
set<ll> keys;
ll hash_str(){
    ll ret = 0;
    for(int i=0; i<k; ++i)
        ret = ret*3 + (str[i]=='S'?0:(str[i]=='E'?1:2));

    return ret;
}
ll get_last(ll x, ll y){
    ll z = 0, t=1;
    for(int i=0; i<k; ++i){
        if(x%3 == y%3) z += t*(x%3);
        else z += t*(3 - (x%3) - (y%3));
        t*=3;
        x/=3; y/=3;
    }
    return z;
}
int main()
{
    int i;
    scanf("%d%d", &n, &k);
    for(i=1; i<=n; ++i){
        scanf("%s", str);
        ll key = hash_str();
        keys.insert(key);
        arr[i] = key;
    }
    ll ans = 0;
    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            ll newkey = get_last(arr[i], arr[j]);
            if(keys.find(newkey) == keys.end()) continue;
            ++ans;
        }
    }
    printf("%lld\n", ans/3);
}