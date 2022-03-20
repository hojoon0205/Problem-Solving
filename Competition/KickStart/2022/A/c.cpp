#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int N;
string S;
string A;
bool back(int idx){
    if(idx >= N) return true;
    if(S[idx]!='?'){
        A[idx] = S[idx];
        if(idx>=4 && A[idx]==A[idx-4] && A[idx-1]==A[idx-3]) return false;
        if(idx>=5 && A[idx]==A[idx-5] && A[idx-1]==A[idx-4] && A[idx-2]==A[idx-3]) return false;
        if(back(idx+1)) return true;
        return false;
    }
    if(S[idx]=='?'){
        bool able0 = true, able1 = true;
        A[idx] = '0';
        if(idx>=4 && A[idx]==A[idx-4] && A[idx-1]==A[idx-3]) able0 = false;
        if(idx>=5 && A[idx]==A[idx-5] && A[idx-1]==A[idx-4] && A[idx-2]==A[idx-3]) able0 = false;
        if(able0) able0 = back(idx+1);
        A[idx] = '1';
        if(idx>=4 && A[idx]==A[idx-4] && A[idx-1]==A[idx-3]) able1 = false;
        if(idx>=5 && A[idx]==A[idx-5] && A[idx-1]==A[idx-4] && A[idx-2]==A[idx-3]) able1 = false;
        if(able1) able1 = back(idx+1);
        return able0||able1;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        cout << "Case #" << tt << ": ";
        cin >> N >> S; A=S;
        if(N<=15){
            bool possi = false;
            for(int C=0; C<(1<<N); ++C){
                bool chk = true;
                for(int i=0; i<N; ++i){
                    if(S[i]!='?' && S[i]-'0'!=((C>>i)&1)){ chk = false; break; }
                }
                if(!chk) continue;
                //for(int i=0; i<N; ++i) cout << ((C>>i)&1);
                //cout << endl;
                for(int l=5; l<=N; ++l){
                    int mask = (1<<l)-1;
                    for(int p=0; p<=N-l; ++p){
                        int X = (C>>p)&mask;
                        int Y = 0;
                        for(int i=0; i<l; ++i) Y = (Y<<1)|((X>>i)&1);
                        //if(l==6) cout << X << "," << Y << endl;
                        if(X==Y){ chk = false; break; }
                    }
                }
                if(chk){ possi = true; break; }
            }
            cout << (possi?"":"IM") << "POSSIBLE\n";
            continue;
        }
        cout << (back(0)?"POSSIBLE\n":"IMPOSSIBLE\n");
    }
}