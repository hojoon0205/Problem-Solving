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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<pll> edges(m);
    string Q(m, '0');
    for(int i=0; i<m; ++i){
        Q[i] = '1';
        cout << "? " << Q << endl;
        cin >> edges[i].fi;
        Q[i] = '0';
        edges[i].se = i;
    }
    sort(edges.begin(), edges.end());
    ll s = 0;
    for(int i=0; i<m; ++i){
        int idx = edges[i].se;
        ll ss = s + edges[i].fi;
        Q[idx] = '1';
        cout << "? " << Q << endl;
        ll ret;
        cin >> ret;
        if(ret != ss){
            Q[idx] = '0';
        }
        else{
            s = ret;
        }
    }
    cout << "! " << s << endl;
}