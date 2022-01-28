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

    int T; cin >> T;
    for(;T--;){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i=0; i<n; ++i) cin >> a[i];
        vi b = a;
        sort(b.begin(), b.end());
        int l=0, r=(n+k-1)/2;
        int x, y, md = n;
        for(;r<n;++l,++r){
            if(b[r]-b[l] < md){
                md = b[r]-b[l];
                x = b[l]; y = b[r];
            }
        }
        cout << x << " " << y << "\n";
        vector<pii> ans; l=0;
        int c = 0;
        for(r=0; r<n && k; ++r){
            if(x <= a[r] && a[r] <= y){
                ++c;
                if(c>0){
                    ans.pb({l+1,r+1});
                    l = r+1; c=0; --k;
                }
            }
            else --c;
        }
        ans.back().se = n;
        for(auto &p : ans) cout << p.fi << " " << p.se << "\n";
    }
}