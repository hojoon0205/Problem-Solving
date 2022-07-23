#include<bits/stdc++.h>
using namespace std;

struct A{
    char Bot;
    string Act;
    int num;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    vector<A> tmp;
    vector<A> ans;
    vector<A> in(M);
    set<int> st;
    bool isin1 = false;
    for(int i=1; i<=2*N; ++i) st.insert(i);
    for(int i=0; i<M; ++i){
        string x;
        cin >> x >> in[i].Act >> in[i].num;
        if(in[i].num == 1) isin1 = true;
        in[i].Bot = x[0];
        st.erase(in[i].num);
    }
    if(!isin1){ cout << "NO\n"; return 0; }
    for(int i=0; i<M; ++i){
        if(i==0){ tmp.push_back(in[i]); continue; }
        if(in[i-1].Bot == in[i].Bot){
            int t = tmp.back().num;
            auto it = st.upper_bound(t);
            if(it==st.end()){
                cout << "NO\n"; return 0;
            }
            t = *it;
            tmp.push_back({'A'+'B'-in[i-1].Bot, "CHAIN", t});
            st.erase(it);
        }
        tmp.push_back(in[i]);
    }
    if(tmp.back().Bot == 'A'){
        int t = tmp.back().num;
        auto it = st.upper_bound(t);
        if(it==st.end()){
            cout << "NO\n"; return 0;
        }
        t = *it;
        tmp.push_back({'B', "CHAIN", t});
        st.erase(it);
    }
    int b = *st.begin();
    for(int i=0; i<tmp.size(); ++i){
        auto tt = tmp[i];
        ans.push_back(tt);
        if(tt.num == b-1){
            for(int x : st){
                ans.push_back({'A'+'B'-ans.back().Bot, "CHAIN", x});
            }
        }
    }
    if(ans.size() != 2*N){
        cout << "NO\n"; return 0;
    }
    cout << "YES\n";
    for(auto tt : ans){
        cout << tt.Bot << " " << tt.Act << " " << tt.num << "\n";
    }
}