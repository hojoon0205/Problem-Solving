#include<bits/stdc++.h>
using namespace std;

using ld = long double;
using pdd = pair<ld,ld>;
const ld eps = 1e-9;

#define fi first
#define se second
#define pb push_back

ld dist(pdd a, pdd b){
    return sqrt( (a.fi-b.fi)*(a.fi-b.fi) + (a.se-b.se)*(a.se-b.se) );
}

int main(){
    int N,M; cin >> N >> M;
    ld n=N, m=M;

    cout << fixed;
    cout.precision(10);
    ld L; cin >> L;
    if(L*L-eps < n*n + m*m && n*n+m*m < L*L+eps){
        cout << "2\n0 0\n" << n << " " << m << endl;
        return 0;
    }
    vector<pdd> ans;
    ans.pb({0.0,0.0});
    ld cL = 0.0;
    for(int y=0; y<=M; ++y){
        if(y%2==0){
            if( cL + dist(ans.back(), {n,m}) - eps < L
             && cL + dist(ans.back(), {n,(ld)y}) + dist({n,(ld)y}, {n,m}) + eps > L){

                ld l = 0.0, r = n;
                for(int i=0; i<=100; ++i){
                    ld mi = (l+r)/2.0;
                    ld D = cL + dist(ans.back(), {mi,(ld)y}) + dist({mi,(ld)y}, {n,m});
                    if(L <= D-eps) r = mi;
                    else if(L >= D+eps) l = mi;
                    else{
                        ans.pb({mi,(ld)y});
                        ans.pb({n,m});
                        cout << ans.size() << "\n";
                        for(auto &p : ans){
                            cout << p.fi << " " << p.se << "\n";
                        }
                        return 0;
                    }
                }

            }
            else{ cL += dist(ans.back(), {n,(ld)y}); ans.pb({n,(ld)y}); }
        }
        else{
            if( cL + dist(ans.back(), {n,m}) - eps < L
             && cL + dist(ans.back(), {0,(ld)y}) + dist({0,(ld)y}, {n,m}) + eps > L){

                ld l = 0.0, r = n;
                for(int i=0; i<=100; ++i){
                    ld mi = (l+r)/2.0;
                    ld D = cL + dist(ans.back(), {mi,(ld)y}) + dist({mi,(ld)y}, {n,m});
                    if(L <= D-eps) l = mi;
                    else if(L >= D+eps) r = mi;
                    else{
                        ans.pb({mi,(ld)y});
                        ans.pb({n,m});
                        cout << ans.size() << "\n";
                        for(auto &p : ans){
                            cout << p.fi << " " << p.se << "\n";
                        }
                        return 0;
                    }
                }
            }
            else{ cL += dist(ans.back(), {0,(ld)y}); ans.pb({0,(ld)y}); }
        }
    }
}