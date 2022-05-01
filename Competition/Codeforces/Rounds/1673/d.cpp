#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
#define fi first
#define se second
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

const ll MOD = 1e9+7;

ll get_ans(ll p, ll b, ll q, ll y, ll c, ll r, ll z){
    if(__gcd(p,q) * r != p*q) return 0;
    if(c-r < b) return -1;
    if(c+r*z > b+q*(y-1)) return -1;
    //if(r==12) cout << "p: " << p << endl;
    return (r/p)*(r/p)%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;

    for(;T--;){
        ll p;
        ll b, q, y; cin >> b >> q >> y;
        ll c, r, z; cin >> c >> r >> z;
        if(r%q != 0){ cout << "0\n"; continue; }
        if(c < b || b+q*(y-1) < c+r*(z-1)){ cout << "0\n"; continue; }
        if((c - b)%q != 0){ cout << "0\n"; continue; }
        bool infi = false;
        ll ans = 0;
        for(ll i=1; i*i <= q; ++i){
            p = i * (r/q);
            ll ret1 = get_ans(p, b, q, y, c, r, z);
            if(ret1 < 0){ infi = true; break; }
            ans = (ans+ret1)%MOD;
            if(i*i==q) break;
            p = (q/i) * (r/q);
            ll ret2 = get_ans(p, b, q, y, c, r, z);
            if(ret2 < 0){ infi = true; break; }
            ans = (ans+ret2)%MOD;
        }
        if(infi) cout << "-1\n";
        else cout << ans << "\n";
    }
}