// TLE
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll, pair<ll,ll>> plll;

const ll INF = 1e18;

#define F first
#define S second
#define MP make_pair

priority_queue<plll, vector<plll>, greater<plll>> Q;
vector<pair<int,pll>> graph[60];
int N, M;
map<ll,ll> ans[60];
map<ll,bool> chk[60];
ll S;
ll C[60], D[60];
bool vis[60];
ll remain;

int main()
{
    scanf("%d%d%lld", &N, &M, &S);
    for(int i=1; i<=M; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        ll c, m;
        scanf("%lld%lld", &c, &m);
        graph[x].push_back(MP(y, MP(m, c)));
        graph[y].push_back(MP(x, MP(m, c)));
    }
    for(int i=1; i<=N; ++i){
        scanf("%lld%lld", &C[i], &D[i]);
    }
    ans[1][S>5000?INF:S] = 0; Q.push(MP(0, MP(1, S>5000?INF:S)));
    for(ll i=S+C[1]; ; i+=C[1]){
        ll cc = i>5000?INF:i;
        ans[1][cc] = (i-S)/C[1]*D[1];
        Q.push(MP((i-S)/C[1]*D[1], MP(1, cc)));
        if(i > 5000) break;
    }
    remain = N;
    while(!Q.empty() && remain > 0){
        plll T = Q.top(); Q.pop();
        ll min = T.F;
        ll cur = T.S.F;
        ll cost = T.S.S;
        if(vis[cur] == false) --remain;
        vis[cur] = true;
        //printf("%lld %lld %lld\n", cur, min, cost);
        printf("Heap Size: %lld\n", Q.size());
        if(ans[cur][cost] < min) continue;
        if(ans[cur][cost] == min && chk[cur].find(cost) != chk[cur].find(cost)) continue;
        chk[cur][cost] = true;
        if(cost < 5000){
            for(ll i=cost+C[cur]; ; i+=C[cur]){
                ll tmp = min + (i-cost)/C[cur]*D[cur];
                ll cc = i>5000?INF:i;
                if(ans[cur].find(cc) == ans[cur].end() || ans[cur][cc] > tmp){
                    ans[cur][cc] = tmp;
                    Q.push(MP(tmp, MP(cur, cc)));
                }
                if(i > 5000) break;
            }
        }
        for(auto X : graph[cur]){
            ll nex = X.F;
            ll mi = X.S.F;
            ll co = X.S.S;
            if(cost < co) continue;
            ll nco = (cost-co)>5000?INF:(cost-co);
            if(ans[nex].find(nco) == ans[nex].end() || ans[nex][nco] > min+mi){
                ans[nex][nco] = min+mi;
                Q.push(MP(min+mi, MP(nex, nco)));
            }
        }
    }
    for(int i=2; i<=N; ++i){
        ll a = INF;
        for(auto X : ans[i]){
            a = min(X.S, a);
        }
        printf("%lld\n", a);
    }
}