#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
#define x first
#define y second

bool chk[30][30];
int C = 15, N = 10;
pii F6[6] = {{9,9},{0,9},{-9,0},{-9,-9},{0,-9},{9,0}};
map<pii,pair<pii,pii>> Danger;
pii next_pos[6] = {{1,1},{0,1},{-1,0},{-1,-1},{0,-1},{1,0}};

bool check(pii pos){
    pos.x += C; pos.y += C;
    if(chk[pos.x][pos.y]) return true;
    chk[pos.x][pos.y] = true;
    return false;
}

bool isinarea(pii pos){
    if(pos.x <= -N && N <= pos.x) return false;
    if(max(-N+pos.x, -N) < pos.y && pos.y < min(N, N+pos.x)) return true;
    return false;
}

bool isonedge(pii pos, int Anum){
    if(!isinarea(pos)) return false;
    if(pos.x==Anum && pos.y >= 0 && pos.y <= Anum) return true;
    if(pos.x==-Anum && pos.y >= -Anum && pos.y <= 0) return true;
    if(pos.y==Anum && pos.x >= 0 && pos.x <= Anum) return true;
    if(pos.y==-Anum && pos.x >= -Anum && pos.x <= 0) return true;
    if(pos.x-pos.y == Anum && pos.x >= 0 && pos.y <= 0) return true;
    if(pos.x-pos.y == -Anum && pos.x <= 0 && pos.y >= 0) return true;
    return false;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    Danger[{7,7}] = Danger[{6,6}] = {{8,9}, {9,8}};
    Danger[{0,7}] = Danger[{0,6}] = {{-1,8},{1,9}};
    Danger[{-7,0}] = Danger[{-6,0}] = {{-9,-1},{-8,1}};
    Danger[{-7,-7}] = Danger[{-6,-6}] = {{-8,-9},{-9,-8}};
    Danger[{0,-7}] = Danger[{0,-6}] = {{1,-8},{-1,-9}};
    Danger[{7,0}] = Danger[{6,0}] = {{9,1},{8,-1}};

    int cnt = 0;
    pii cat={0,0};
    while(true){
        bool canmove = false;
        for(auto dxy : next_pos){
            pii nex = {cat.x + dxy.x, cat.y + dxy.y};
            if(!chk[nex.x+C][nex.y+C]) canmove = true;
        }
        if(!canmove) break;
        ++cnt;
        //cout << "Cat move: "; cout.flush();
        int cx, cy; cin >> cx >> cy;
        cat = {cx,cy};
        if(cnt <= 6) {
            cout << F6[cnt-1].x << " " << F6[cnt-1].y << endl;
            check(F6[cnt-1]);
            continue;
        }
        if(Danger.count(cat)){
            //looking first one
            pii nex = Danger[cat].first;
            int cntchk = 0;
            for(auto dxy : next_pos){
                pii nexnex = {nex.x + dxy.x, nex.y + dxy.y};
                if(!isinarea(nexnex)) continue;
                if(!isonedge(nexnex,9)) continue;
                if(chk[nexnex.x+C][nexnex.y+C]) ++cntchk;
            }
            if(cntchk<=1 && !chk[nex.x+C][nex.y+C]){
                if(!check(Danger[cat].first)){
                    cout << Danger[cat].first.x << " " << Danger[cat].first.y << endl;
                    continue;
                }
            }
            else{
                if(!check(Danger[cat].second)){
                    cout << Danger[cat].second.x << " " << Danger[cat].second.y << endl;
                    continue;
                }
            }
        }
        else if(isonedge(cat,7)){
            if(Danger.count(cat)){
                if(!check(Danger[cat].first)){
                    cout << Danger[cat].first.x << " " << Danger[cat].first.y << endl;
                    continue;
                }
                if(!check(Danger[cat].second)){
                    cout << Danger[cat].second.x << " " << Danger[cat].second.y << endl;
                    continue;
                }
            }
            else{
                bool out = false;
                for(int i=1; i<=6; ++i){
                    if(cat == make_pair(7,i)) { if(!check({9,i+1})){ out = true; cout << 9 << " " << i+1 << endl; break; } }
                    if(cat == make_pair(i,7)) { if(!check({i+1,9})){ out = true; cout << i+1 << " " << 9 << endl; break; } }
                    if(cat == make_pair(i-7,i)) { if(!check({i-8,i+1})){ out = true; cout << i-8 << " " << i+1 << endl; break; } }
                    if(cat == make_pair(-7,-i)) { if(!check({-9,-i-1})){ out = true; cout << -9 << " " << -i-1 << endl; break; } }
                    if(cat == make_pair(-i,-7)) { if(!check({-i-1,-9})){ out = true; cout << -i-1 << " " << -9 << endl; break; } }
                    if(cat == make_pair(i,i-7)) { if(!check({i+1,i-8})){ out = true; cout << i+1 << " " << i-8 << endl; break; } }
                }
                if(out) continue;
            }
        }
        else if(isonedge(cat,8)){
            bool out = false;
            //cout << "Cat current pos : " << cat.first << " " << cat.second << endl;
            for(auto dxy : next_pos){
                pii nex = {dxy.x + cat.x, dxy.y + cat.y};
                if(!isonedge(nex,9)) continue;
                if(!check(nex)){
                    cout << nex.x << " " << nex.y << endl;
                    out = true;
                    break;
                }
            }
            if(out) continue;
        }
        bool outed = false;
        for(int x=-N+1; x<=N-1; ++x){
            for(int y=-N+1; y<=N-1; ++y){
                if(!isonedge({x,y},9)) continue;
                //if(make_pair(x,y)==cat) continue;
                if(!check({x,y})){
                    cout << x << " " << y << endl;
                    outed = true;
                    break;
                }
            }
            if(outed) break;
        }
        if(outed) continue;
        for(int x=-N+1; x<=N-1; ++x){
            bool out = false;
            for(int y=-N+1; y<=N-1; ++y){
                if(!isinarea({x,y})) continue;
                if(make_pair(x,y)==cat) continue;
                if(!check({x,y})){
                    cout << x << " " << y << endl;
                    out = true;
                    break;
                }
            }
            if(out) break;
        }
    }
}