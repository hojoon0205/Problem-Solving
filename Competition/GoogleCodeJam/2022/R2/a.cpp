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

bool inXtharea(int N, int r, int c, int X){
    r = min(r, N+1-r);
    c = min(c, N+1-c);
    if(min(r,c) == X) return true;
    else return false;
}
pii get_rc(int N, int num){
    if(num==N*N) return {(N+1)/2, (N+1)/2};
    int tmp = 0;
    for(int x=1; x<=(N+1)/2; ++x){
        int l = (N+1-2*x);
        if(tmp + l*4 < num){ tmp += l*4; continue; }
        if(tmp + l >= num) return {x, x+num-tmp-1};
        else if(tmp + l*2 >= num) return {num-tmp-l-1+x, N+1-x};
        else if(tmp + l*3 >= num) return {N+1-x, N+1-x - (num-tmp-l*2-1)};
        else if(tmp + l*4 >= num) return {N+1-x - (num-tmp-l*3-1), x};
    }
    return {-1,-1};
}
int get_num(int N, int r, int c){
    if(r==(N+1)/2 && c==(N+1)/2) return N*N;
    int num = 0;
    for(int i=1; i<=(N+1)/2; ++i){
        if(!inXtharea(N, r, c, i)){
            num += 4 * (N+1-2*i);
            continue;
        }
        r -= (i-1); c -= (i-1); N -= 2*(i-1);
        //cout << i << "," << r << "," << c << "," << N << "," << num << endl;
        if(r==1 && c<N) num += c;
        else if(c==N && r<N) num += N-1 + r;
        else if(r==N && c>1) num += 2*(N-1) + (N+1-c);
        else if(c==1 && r>1) num += 3*(N-1) + (N+1-r);
        return num;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //cout << get_num(39, 21, 20) << endl;

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        int N, K; cin >> N >> K;
        if(K < N-1 || K%2){ cout << "Case #" << tt << ": IMPOSSIBLE\n"; continue; }
        int tmp = 0;
        bool findans = false;
        vector<pii> ans;
        int x;
        for(x=1; x<(N+1)/2; tmp += 4*(N+1-2*x), x+=1){
            if(K >= tmp + 4*(N+1-2*x) + (N-1-2*x)) continue;
            int r = x, c = x, num = tmp+1;
            //cout << "Case " << tt << ": " << x << "," << r << " " << c << " " << num << endl;
            for(; !findans && c<N+1-x; ++c,++num){
                if(K != num-1 + abs((N+1)/2 - r) + abs((N+1)/2 - c)) continue;
                findans = true;
                int curnum = num;
                while(r != (N+1)/2 || c != (N+1)/2){
                    //cout << r << "," << c << " " << curnum << " / ";
                    for(int i=0; i<4; ++i){
                        int nr = r+"1120"[i]-'1', nc = c+"0211"[i]-'1';
                        if(min(r,(N+1)/2)>nr || nr>max(r,(N+1)/2) || min(c,(N+1)/2)>nc || nc>max(c,(N+1)/2)) continue;
                        int nex = get_num(N, nr, nc);
                        if(curnum >= nex) continue;

                        if(nex > curnum+1) ans.push_back({curnum, nex});
                        r=nr; c=nc; curnum = nex; break;
                    }
                }
            }
            for(; !findans && r<N+1-x; ++r,++num){
                if(K != num-1 + abs((N+1)/2 - r) + abs((N+1)/2 - c)) continue;
                findans = true;
                int curnum = num;
                while(r != (N+1)/2 || c != (N+1)/2){
                    //cout << r << "," << c << " " << curnum << " / ";
                    for(int i=0; i<4; ++i){
                        int nr = r+"1120"[i]-'1', nc = c+"0211"[i]-'1';
                        if(min(r,(N+1)/2)>nr || nr>max(r,(N+1)/2) || min(c,(N+1)/2)>nc || nc>max(c,(N+1)/2)) continue;
                        int nex = get_num(N, nr, nc);
                        if(curnum >= nex) continue;

                        if(nex > curnum+1) ans.push_back({curnum, nex});
                        r=nr; c=nc; curnum = nex; break;
                    }
                }
            }
            for(; !findans && c>x; --c,++num){
                if(K != num-1 + abs((N+1)/2 - r) + abs((N+1)/2 - c)) continue;
                findans = true;
                int curnum = num;
                while(r != (N+1)/2 || c != (N+1)/2){
                    //cout << r << "," << c << " " << curnum << " / ";
                    for(int i=0; i<4; ++i){
                        int nr = r+"1120"[i]-'1', nc = c+"0211"[i]-'1';
                        if(min(r,(N+1)/2)>nr || nr>max(r,(N+1)/2) || min(c,(N+1)/2)>nc || nc>max(c,(N+1)/2)) continue;
                        int nex = get_num(N, nr, nc);
                        if(curnum >= nex) continue;

                        if(nex > curnum+1) ans.push_back({curnum, nex});
                        r=nr; c=nc; curnum = nex; break;
                    }
                }
            }
            for(; !findans && r>x; --r,++num){
                if(K != num-1 + abs((N+1)/2 - r) + abs((N+1)/2 - c)) continue;
                findans = true;
                int curnum = num;
                while(r != (N+1)/2 || c != (N+1)/2){
                    //cout << r << "," << c << " " << curnum << " / ";
                    for(int i=0; i<4; ++i){
                        int nr = r+"1120"[i]-'1', nc = c+"0211"[i]-'1';
                        if(min(r,(N+1)/2)>nr || nr>max(r,(N+1)/2) || min(c,(N+1)/2)>nc || nc>max(c,(N+1)/2)) continue;
                        int nex = get_num(N, nr, nc);
                        if(curnum >= nex) continue;

                        if(nex > curnum+1) ans.push_back({curnum, nex});
                        r=nr; c=nc; curnum = nex; break;
                    }
                }
            }
            break;
        }
        cout << "Case #" << tt << ": " << ans.size() << "\n";
        for(auto &pi : ans) cout << pi.fi << " " << pi.se << "\n";
    }
}