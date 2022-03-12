#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define fi first
#define se second

vector<ll> primes;
bool isprime(ll X){
    for(auto x : primes){
        if(x==X) return true;
        if(X%x==0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    primes.push_back(2);
    for(int p=3; p*p<=1000000000; p+=2){
        bool chk = true;
        for(auto i : primes){
            if(i*i>p) break;
            if(p%i == 0){ chk = false; break; }
        }
        if(chk) primes.push_back(p);
    }
    int Psz = primes.size();

    int T; cin >> T;
    for(;T--;){
        ll d, x;
        cin >> x >> d;
        if((x/d)%d != 0 || (x==d*d) || isprime(x/d/d)){ cout << "NO\n"; continue; }
        if(isprime(d)){
            ll a = x; while(a%d==0) a/=d;
            if(a==1 || isprime(a)) cout << "NO\n";
            else cout << "YES\n";
            continue;
        }
        ll p;
        for(int i=0; i<Psz; ++i){
            if(d%primes[i]==0){ p = primes[i]; break; }
        }
        ll q = d, m=0; while(q%p==0) m+=1,q/=p;
        if(q!=1){
            cout << "YES\n";
            continue;
        }
        //d = p^t
        ll a = x, n=0; while(a%d==0) n+=1,a/=d;
        if(!(a==1 || isprime(a))){ cout << "YES\n"; continue; }
        if(a!=1 && a!=p){ cout << "YES\n"; continue; }
        if(a==p){
            if(m>=3 || n>=4) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}