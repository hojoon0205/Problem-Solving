#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<int> graph[10010];
int color[10010];

struct Point{
    int idx;
    int x, y;
};

void dfs_col(int node, int c1, int c2){
    if(color[node]==c1 || color[node]==c2)
        color[node] = c1 + c2 - color[node];
    for(auto& nex : graph[node]){
        if(color[nex]!=color[node]) continue;
        dfs_col(nex, c1, c2);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    vector<Point> p, v;
    for(int i=0; i<N; ++i){
        int x, y; cin >> x >> y;
        p.push_back({i, x, y});
    }
    v = p;
    sort(p.begin(), p.end(), [&](Point& a, Point& b)->bool{ return (a.y==b.y)?(a.x<b.x):(a.y<b.y); });
    for(int i=0; i<M; ++i){
        int a, b; cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0; i<N; ++i){
        int node = p[i].idx;
        int c = 0;
        for(auto &a : graph[node]){
            c |= (1<<color[a]);
        }
        for(int col=1; col<=4; ++col){
            if(!(c&(1<<col))){ color[node] = col; break; }
        }
        if(color[node]) continue;
        int n1, n2, n3, n4;
        for(auto &a : graph[node]){
            if(!color[a]) continue;
            if(v[a].y == p[i].y && v[a].x < p[i].x) n1 = a;
            if(v[a].y < p[i].y && v[a].x < p[i].x) n2 = a;
            if(v[a].y < p[i].y && v[a].x == p[i].x) n3 = a;
            if(v[a].y < p[i].y && v[a].x > p[i].x) n4 = a;
        }
        int newcol = color[n1];
        dfs_col(n1, color[n1], color[n3]);
        if(color[n3]==newcol){
            newcol = color[n2];
            dfs_col(n2, color[n2], color[n4]);
        }
        color[node] = newcol;
    }
    for(int i=0; i<N; ++i) cout << color[i] << "\n";
}