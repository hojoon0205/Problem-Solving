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
        set<char> se;
        for(int i=0; i<N; ++i) se.insert(S[i]);
        int t = se.size();
        bool ans = true;
        for(int i=1; i<t; ++i) if(S[i]==S[i-1]) ans = false;
        for(int i=t; i<N; ++i) if(S[i]!=S[i-t]) ans = false;
        cout << (ans?"YES":"NO") << "\n";
    }
}