#include<bits/stdc++.h>
using namespace std;

using ll = int;
#define fi first
#define se second

struct Point{
    ll x, y;
    int idx;
};

struct Pinfo{
    ll y;
    int idx;
    ll l, r;
};

vector<Pinfo> ps[210000];
map<ll, pair<ll,ll>> plr[210000];
const ll B = 500;

ll get_dist(Point A, Point B){
    return abs(A.x-B.x)+abs(A.y-B.y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<Point> p(N), ans(N, {0,0,-1});
    for(int i=0; i<N; ++i){ cin >> p[i].x >> p[i].y; p[i].idx = i; }
    sort(p.begin(), p.end(), [&](Point &a, Point &b)->bool{ return a.x==b.x?a.y<b.y:a.x<b.x; });
    for(auto &po : p){
        ps[po.x+B].push_back({po.y,po.idx,0,0});
    }
    for(int i=0; i<210000; ++i){
        if(ps[i].size()==0) continue;
        int sz = ps[i].size();
        ps[i][0].l = ps[i][0].y-1;
        for(int j=1; j<sz; ++j){
            ps[i][j].l = (ps[i][j-1].y+1==ps[i][j].y)?ps[i][j-1].l:(ps[i][j].y-1);
        }
        ps[i][sz-1].r = ps[i][sz-1].y+1;
        for(int j=sz-2; j>=0; --j){
            ps[i][j].r = (ps[i][j+1].y-1==ps[i][j].y)?ps[i][j+1].r:(ps[i][j].y+1);
        }
        for(auto pi : ps[i]){
            plr[i][pi.y] = {abs(pi.y-pi.l)<abs(pi.y-pi.r)?pi.l:pi.r, pi.idx};
        }
    }
    //cout << "qwer" << endl;
    for(int i=0; i<N; ++i){
        Point P = p[i];
        int id = P.idx;
        ans[id].idx = id;
        ans[id].y = plr[P.x+B][P.y].fi;
        ans[id].x = P.x;
        int d = get_dist(ans[id],P);
        if(d==1) continue;
        int X = P.x - 1;
        if(plr[X+B].empty() || plr[X+B].count(P.y)==0){
            if(d > get_dist({X,P.y,id}, P)){
                ans[id] = {X,P.y,id};
            }
        }
        else if(d > get_dist(ans[plr[X+B][P.y].se], P)){
            ans[id] = ans[plr[X+B][P.y].se];
        }
    }
    for(int i=N-1; i>=0; --i){
        Point P = p[i];
        int id = P.idx;
        int d = get_dist(ans[id],P);
        if(d==1) continue;
        int X = P.x + 1;
        if(plr[X+B].empty() || plr[X+B].count(P.y)==0){
            if(d > get_dist({X,P.y,id}, P)){
                ans[id] = {X,P.y,id};
            }
        }
        else if(d > get_dist(ans[plr[X+B][P.y].se], P)){
            ans[id] = ans[plr[X+B][P.y].se];
        }
    }
    //sort(ans.begin(), ans.end(), [&](Point &a, Point &b)->bool{ return a.idx < b.idx; });
    for(int i=0; i<N; ++i) cout << ans[i].x << " " << ans[i].y << "\n";
}