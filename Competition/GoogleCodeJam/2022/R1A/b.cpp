#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

ll As[2][30], ta[2];
vector<ll> A;
bool chk[1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll D=1;
    for(ll i=0; i<=18; ++i,D*=3){
        As[0][i] = D; As[1][i] = D*2;
        A.push_back(D); A.push_back(D*2);
    } D/=3;
    ta[0] = D/2; ta[1] = ta[0]+1;
    A.push_back(ta[0]); A.push_back(ta[1]);
    ll X = 0;
    while(A.size()<100){
        X += 60+A.size();
        A.push_back(60+A.size());
    }

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        int N; cin >> N; // N = 100
        for(int i=0; i<N; ++i) cout << A[i] << " ";
        cout << endl;
        vector<ll> B(N);
        for(int i=0; i<N; ++i) cin >> B[i];
        sort(B.begin(), B.end());
        vector<ll> ANS; ll S = X;
        for(int i=0; i<N; i+=2) S += B[i+1]-B[i], ANS.push_back(B[i]);
        ll tmp = 1;
        for(int i=0; i<18; ++i,tmp*=3){
            ll d = (S / tmp) % 3;
            if(d==0){
                if(S >= tmp*3){ S -= tmp*3; ANS.push_back(As[0][i]); ANS.push_back(As[1][i]); }
                else S += tmp*3;
            }
            else if(d==1){
                S -= tmp; ANS.push_back(As[1][i]);
            }
            else if(d==2){
                S += tmp; ANS.push_back(As[0][i]);
            }
        }
        // tmp == 3**18
        ll d = (S / tmp) % 3;
        if(S >= tmp*3){
            if(d==1){
                ANS.push_back(As[0][18]);
                ANS.push_back(As[1][18]);
                ANS.push_back(ta[0]);
                ANS.push_back(ta[1]);
            }
        }
        else{
            if(d==0) ANS.push_back(As[1][18]);
            else if(d==2){ ANS.push_back(As[0][18]); ANS.push_back(As[1][18]); }
        }
        for(auto &x : ANS) cout << x << " ";
        cout << endl;
    }
}