#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, K; cin >> N >> K;
    ll a, b, c;
    // a + b + c = N+1
    // a*a + b*b + c*c = 2*K+N+1
    // a>=1 b>=0 c>=0
    for(a=N+1; a>=1; --a){
        ll s = N+1-a;
        ll S = 2*K+N+1-a*a;

        ll l = 0, r = s/2, m; // b>=c
        while(l<=r){
            m = (l+r)/2;
            c = m, b = s-m;
            if(b*b + c*c == S){
                for(int i=1; i<a; ++i) cout << "0 ";
                if(b>0) cout << "1 ";
                for(int i=1; i<b; ++i) cout << "0 ";
                if(c>0) cout << "1 ";
                for(int i=1; i<c; ++i) cout << "0 ";
                cout << endl;
                return 0;
            }
            else if(b*b + c*c < S) r = m-1;
            else l = m+1;
        }
    }
    cout << "-1" << endl;
}