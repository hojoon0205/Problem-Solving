#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

int n;
int arr[510][510];

int par[510];
int sz[510];
int Find(int x){
    return par[x] = (par[x]==x)?x:Find(par[x]);
}
void Union(int x, int y){
    x = Find(x), y = Find(y);
    if(x==y) return;
    par[x] = y;
    sz[y] += sz[x];
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            scanf("%d", &arr[i][j]);
        }
        sz[i] = 1;
        par[i] = i;
    }

    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            //if(i==j) continue;
            if(arr[i][j] && arr[j][i])
                Union(i, j);
        }
    }
    vector<ll> fact(n+1);
    fact[0] = 1;
    for(int i=1; i<=n; ++i) fact[i] = (fact[i-1]*(ll)i)%MOD;
    ll ans = 1;
    for(int i=1; i<=n; ++i){
        vector<bool> chk(n+1, false);
        ll cnt = 0, s = 0;
        for(int j=1; j<=n; ++j){
            if(i==j) continue;
            if(arr[i][j]==0) continue;
            if(Find(i)==Find(j)) continue;
            int x = Find(j);
            if(chk[x]) continue;
            //printf("%d %d\n", i, j);
            chk[x] = true;
            ++cnt;
            s = sz[x];
        }
        //printf("%d %lld %lld\n", i, cnt, s);
        if(cnt!=1) continue;
        ans = (ans*s)%MOD;
        //ans = (ans*fact[s-1])%MOD;
    }
    vector<bool> chk(n+1, false);
    for(int i=1; i<=n; ++i){
        int x = Find(i);
        if(chk[x]) continue;
        chk[x] = true;
        ans = (ans*fact[sz[x]-1])%MOD;
    }
    printf("%lld\n", ans);
}