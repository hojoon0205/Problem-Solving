#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAGICNUM = 100000;
const int MAXI = 1000000010;
vector<int> chk;
vector<int> primes;

bool miller_rabin(ll X){
    if(X==1) return false;
    ll D = X-1; while(D%2==0) D/=2;
    for(ll a : {2,7,61}){
        if(X%a==0 && X!=a) return false;
        bool maybeprime = false;
        ll t = 1;
        for(ll tmp = D,x=a; tmp; tmp>>=1){
            if(tmp&1) t = (t*x)%X;
            x = (x*x)%X;
        }
        if(t==1) maybeprime = true;
        else{
            for(ll P=D; P<X-1; P*=2){
                if(t==X-1){ maybeprime = true; break; }
                t = (t*t)%X;
            }
        }
        if(!maybeprime) return false;
    }
    return true;
}
/*
bool check(int X){
    return chk.find(X)==chk.end()?miller_rabin(X):true;
}
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int p=3; p<=MAGICNUM; p+=2){
        bool isprime = true;
        for(auto x : primes){
            if(x*x > p) break;
            if(p%x==0){ isprime = false; break; }
        }
        if(!isprime) continue;
        primes.push_back(p);
        for(ll i=p; i<=MAXI; i*=p) chk.push_back(i);
    }
    sort(chk.begin(), chk.end());

    int TC; cin >> TC;
    for(;TC--;){
        int K; cin >> K;
        int ans = 0;
        //p>=3
        for(int t=1; t*t<=K; ++t){
            if(K%t) continue;
            int D = K/t;
            if((D+2)%t == 0){
                int X = (D+2)/t;
                if(binary_search(chk.begin(), chk.end(), X) || (X>MAGICNUM && miller_rabin(X))) ++ans;
            }
            if((D-2)%t == 0){
                int X = (D-2)/t;
                if(binary_search(chk.begin(), chk.end(), X) || (X>MAGICNUM && miller_rabin(X))) ++ans;
            }
        }
        //p==2 && m>=2
        for(int t=1; t*t<=K; ++t){
            if(K%t) continue;
            int D = K/t;
            if((D+1)%t == 0){
                int X = (D+1)/t;
                while(X && X%2==0) X/=2;
                ans += (X==1)?1:0;
            }
            if((D-1)%t == 0){
                int X = (D-1)/t;
                while(X && X%2==0) X/=2;
                ans += (X==1)?1:0;
            }
        }
        //p==2 && m==1
        if(K%2==0){
            int n; for(n=1;n*n<2*K+1;++n);
            if(n*n == 2*K+1) ++ans;
        }
        cout << ans << endl;
    }
}