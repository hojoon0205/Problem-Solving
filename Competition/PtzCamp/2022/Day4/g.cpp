#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    const int B = 15;
    map<ll,ll> pre;
    for(int i=0; i<(1<<B); ++i){
        ll c = 0;
        for(int j=1; j<=B; ++j){
            if((1<<(j-1))&i) c += (1<<j);
            else c *= (1<<j);
            c %= MOD;
        }
        pre[c] = i;
    }

    int N; cin >> N;
    string ANS(N,' ');
    for(int r=N; r>=B; r-=B){
        int l = max(r-B,0);
        vector<int> q(N+1);
        for(int j=0; j<=l; ++j) q[j] = 0;
        for(int j=l+1; j<=r; ++j) q[j] = (1<<(j-l));
        for(int j=r+1; j<=N; ++j){
            if(ANS[j-1]=='x') q[j] = 1;
            else q[j] = 0;
        }
        
        // ask query
        cout << "?";
        for(int j=0; j<=N; ++j){
            cout << " " << q[j];
        }
        cout << endl;

        // get answer
        ll ret; cin >> ret;

        ll c = pre[ret];
        for(int j=1; j<=B; ++j){
            if((1<<(j-1))&c) ANS[l+j-1] = '+';
            else ANS[l+j-1] = 'x';
        }
    }
    if(N%B==0){
        cout << "! " << ANS << endl;
        return 0;
    }

    int r = N%B;
    pre.clear();
    for(int i=0; i<(1<<r); ++i){
        ll c = 0;
        for(int j=1; j<=r; ++j){
            if((1<<(j-1))&i) c += (1<<j);
            else c *= (1<<j);
            c %= MOD;
        }
        pre[c] = i;
    }

    vector<int> q(N+1, 0);
    for(int j=1; j<=r; ++j) q[j] = (1<<j);
    for(int j=r+1; j<=N; ++j){
        if(ANS[j-1]=='x') q[j] = 1;
        else q[j] = 0;
    }
    
    // ask query
    cout << "?";
    for(int j=0; j<=N; ++j){
        cout << " " << q[j];
    }
    cout << endl;

    // get answer
    ll ret; cin >> ret;

    ll c = pre[ret];
    for(int j=1; j<=r; ++j){
        if((1<<(j-1))&c) ANS[j-1] = '+';
        else ANS[j-1] = 'x';
    }

    cout << "! " << ANS << endl;
}