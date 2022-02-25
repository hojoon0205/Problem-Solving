#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct Point{
    ll x, y, G;
};

ll ccw(Point a, Point b, Point c){ // >0:CCW, ==0:line, <0:CW
    return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}
int area(Point p){
    if(p.x==0 && p.y==0) return 0;
    if(p.x>0 && p.y>=0) return 1;
    if(p.x<=0 && p.y>0) return 2;
    if(p.x<0 && p.y<=0) return 3;
    if(p.x>=0 && p.y<0) return 4;
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<Point> P(N);
    for(int i=0; i<N; ++i) cin >> P[i].x >> P[i].y >> P[i].G;
    if(N==2){ cout << "0\n"; return 0; }
    vector<Point> tmp(P);
    ll ans = (ll)N * 2000000000;
    for(Point &p : P){
        sort(tmp.begin(), tmp.end(), [&](Point &_a, Point &_b)->bool{
            Point a = {_a.x - p.x, _a.y - p.y, _a.G};
            Point b = {_b.x - p.x, _b.y - p.y, _b.G};
            int xa = area(a), xb = area(b);
            if(xa != xb) return xa < xb;
            ll c = ccw(a, {0,0,0}, b);
            return c < 0;
        });
        int T = 1;
        while(T < N && area({tmp[T].x-p.x, tmp[T].y-p.y, 0})<3) ++T;
        ll S1 = 0, S2 = 0;
        for(int i=1; i<T; ++i) S1 += tmp[i].G;
        for(int i=T; i<N; ++i) S2 += tmp[i].G;
        
        int p1 = 1, p2 = T;
        while(p1 < T && p2 < N){
            Point P1 = tmp[p1], P2 = tmp[p2];
            ll c = ccw(P1, p, P2);
            if(c > 0){ //P1
                S1 -= tmp[p1].G;
                ans = min(ans, abs(S1 - S2));
                S2 += tmp[p1].G;
                ++p1;
            }
            else{ //P2
                S2 -= tmp[p2].G;
                ans = min(ans, abs(S1 - S2));
                S1 += tmp[p2].G;
                ++p2;
            }
        }
        while(p1 < T){
            Point P1 = tmp[p1];
            S1 -= tmp[p1].G;
            ans = min(ans, abs(S1 - S2));
            S2 += tmp[p1].G;
            ++p1;
        }
        while(p2 < N){
            Point P2 = tmp[p2];
            S2 -= tmp[p2].G;
            ans = min(ans, abs(S1 - S2));
            S1 += tmp[p2].G;
            ++p2;
        }
    }
    cout << ans << endl;
}