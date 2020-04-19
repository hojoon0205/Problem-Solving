#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define MP make_pair
#define F first
#define S second

ll N;
ll f[200010], inv[200010], finv[200010];
ll pfinv[200010], pC[200010];

vector<plll> graph[200010];

pll *parent[200010];

ll modinv(ll x){
    ll ret=1, po=MOD-2;
    while(po){
        if(po&1) ret = (ret*x)%MOD;
        po>>=1; x=(x*x)%MOD;
    }
    return ret;
}

pll get_ans(ll node, ll prev){
    ll ssize = 1, ret = 1;
    pfinv[node] = pC[node] = 1;
    for(auto &X : graph[node]){
        if(X.F == prev){ parent[node] = &X.S; continue; }
        if(X.S.F==0){
            ll nex = X.F;
            auto a = get_ans(nex, node);
            X.S = a;
        }
        ssize += X.S.F;
        ret = (ret*X.S.S)%MOD;
        ret = (ret*finv[X.S.F])%MOD;
        pfinv[node] = (pfinv[node]*finv[X.S.F])%MOD;
        pC[node] = (pC[node]*X.S.S)%MOD;
    }
    if(prev){
        pfinv[node] = (pfinv[node]*finv[N-ssize])%MOD;
    }
    ret = (ret*f[ssize-1])%MOD;
    return MP(ssize, ret);
}

void get_ans_inv(ll node, ll prev){
    for(auto &X : graph[node]){
        if(X.F == prev) continue;
        ll Si = (N-X.S.F);
        ll nex = X.F;
        parent[nex]->F = Si;
        ll tmp = (((f[Si-1]*pfinv[node])%MOD)*f[X.S.F])%MOD;
        tmp = (((tmp*pC[node])%MOD)*modinv(X.S.S))%MOD;
        parent[nex]->S = tmp;
        pC[nex] = (pC[nex]*tmp)%MOD;
        get_ans_inv(nex, node);
    }
}

int main()
{
    scanf("%lld", &N);
    f[0] = inv[1] = finv[0] = 1;
    for(int i=1; i<=N; ++i) f[i] = (f[i-1]*i)%MOD;
    for(int i=2; i<=N; ++i) inv[i] = ((-inv[MOD%i]*(MOD/i))%MOD + MOD)%MOD;
    for(int i=1; i<=N; ++i) finv[i] = (finv[i-1]*inv[i])%MOD;

    for(int i=1; i<N; ++i){
        ll x, y;
        scanf("%lld%lld", &x, &y);
        graph[x].push_back(MP(y,MP(0,0)));
        graph[y].push_back(MP(x,MP(0,0)));
    }

    get_ans(1,0);
    get_ans_inv(1,0);

    // for(int i=1; i<=N; ++i){
    //     printf("Node: %d\n", i);
    //     for(auto X : graph[i]){
    //         printf("{%lld, {%lld, %lld}},  ", X.F, X.S.F, X.S.S);
    //     }
    //     printf("\n\n");
    // }

    for(int i=1; i<=N; ++i){
        printf("%lld\n", get_ans(i, 0).S);
    }
}