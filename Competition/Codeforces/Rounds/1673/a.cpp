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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        string S; cin >> S;
        int N = S.length();
        int su = 0;
        int alice = 0, bob = 0;
        for(int i=0; i<N; ++i) su += S[i]-'a'+1;
        if(N%2==0) alice = su;
        else{ bob = min(S[0], S[N-1])-'a'+1; alice = su-bob; }
        cout << (alice>bob?"Alice":"Bob") << " " << abs(alice-bob) << "\n";
    }
}