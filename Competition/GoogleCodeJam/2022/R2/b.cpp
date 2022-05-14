#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
#define fi first
#define se second

int arr[210][210], Base;
int chk[210][210];

void draw_circle_perimeter(int R){
    for(int x=-R; x<=R; ++x){
        int y = (int)(sqrt((double)(R*R-x*x))+0.5);
        arr[x+Base][y+Base] = 1;
        arr[x+Base][-y+Base] = 1;
        arr[y+Base][x+Base] = 1;
        arr[-y+Base][x+Base] = 1;
    }
}
void draw_filled_circle(int R){
    for(int x=-R; x<=R; ++x){
        for(int y=-R; y<=R; ++y){
            if((int)(sqrt((double)(x*x+y*y))+0.5) <= R){
                chk[x+Base][y+Base] = 1;
            }
        }
    }
}
void draw_circle_filled_wrong(int R){
    for(int r=0; r<=R; ++r){
        draw_circle_perimeter(r);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        int N; cin >> N;
        Base = 104;
        memset(arr, 0, sizeof(arr));
        memset(chk, 0, sizeof(chk));
        draw_filled_circle(N);
        draw_circle_filled_wrong(N);
        int ans = 0;
        for(int i=0; i<210; ++i){
            for(int j=0; j<210; ++j){
                ans += (arr[i][j]!=chk[i][j])?1:0;
            }
        }
        cout << "Case #" << tt << ": " << ans << "\n";
    }
}