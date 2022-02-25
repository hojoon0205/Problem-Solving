#include<bits/stdc++.h>
using namespace std;

struct T{
    string str;
    int low, high;
};
vector<T> V;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    V.resize(N);
    int O = 0;
    for(int i=0; i<N; ++i){
        cin >> V[i].str >> V[i].low; V[i].high = V[i].low;
        O += V[i].low * 100;
        if(V[i].high == 100) V[i].high = 10000;
        else V[i].high = V[i].high * 100 + 49;
        if(V[i].low > 0) V[i].low = V[i].low * 100 - 50;
    }
    int L=0, H=0;
    for(auto x : V) L+=x.low, H+=x.high;
    if(H<10000 || L>10000){ cout << "IMPOSSIBLE\n"; return 0; }
    for(int i=0; i<N; ++i){
        V[i].low = max(V[i].low, V[i].high - (H - 10000));
        V[i].high= min(V[i].high,V[i].low + (10000-L));
        if(V[i].high < V[i].low){ cout << "IMPOSSIBLE\n"; return 0; }
    }
    for(auto x : V) cout << x.str << " " << x.low/100 << "." << (x.low/10)%10 << x.low%10 << " " << x.high/100 << "." << (x.high/10)%10 << x.high%10 << "\n";
}