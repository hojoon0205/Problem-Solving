#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T,vector<T>,greater<T>>;
#define fi first
#define se second
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vi a(n); for(auto &x : a) cin >> x;
    int ans = 0;
    vector<pii> t(n+1,{-1,-1});
    vi A;
    for(int i=0; i<n; ++i) if(t[a[i]].fi == -1) t[a[i]].fi = i;
    for(int i=n-1; i>=0; --i) if(t[a[i]].se == -1) t[a[i]].se = i;
    for(int i=0; i<n; ++i){
        if(t[a[i]].fi == i || t[a[i]].se == i) A.pb(a[i]);
        else ++ans;
    }
    //cout << ans << endl;
    int N = A.size();
    t.clear(); t.resize(n+1,{-1,-1});
    for(int i=0; i<N; ++i) if(t[A[i]].fi == -1) t[A[i]].fi = i;
    for(int i=N-1; i>=0; --i) if(t[A[i]].se == -1) t[A[i]].se = i;
    int surv = 0, R = -1;
    for(int i=0; i<N; ++i){
        if(i>R){ ++surv; R=t[A[i]].se; }
        if(i==R) continue;
        while(1){
            int nR = R;
            while(i<R){
                if(nR < t[A[i]].se) nR = t[A[i]].se;
                ++i;
            }
            if(nR>R){ ++surv; R=nR; }
            else break;
        }
        ++surv;
        //cout << surv << endl;
    }
    cout << n - surv << endl;
}
