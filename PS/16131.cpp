#include<bits/stdc++.h>
using namespace std;

bool check(int good, int bad){
    if(good>=0 && bad>=0 && bad>=good+2) return true;
    if(good>=0 && bad<0) return false;
    if(good<0 && bad>=0) return true;
    if(good<0 && bad<0 && bad>=good+4) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    int N, A, B, M; cin >> N >> A >> B >> M;
    int tot=0, con=0, maxcon=0; --A;
    if(A<=B){ ++tot; ++con; ++maxcon; }
    vector<int> room(N);
    for(int i=0; i<N; ++i) room[i] = i;
    for(M--;M--;){
        vector<int> score(N);
        for(int i=0; i<N; ++i) cin >> score[i];
        for(int i=0; i<N; ++i){
            int x; cin >> x;
            score[i] -= x;
        }
        for(int i=0; i<N-1; ++i){
            int r1 = room[i], r2 = room[i+1];
            if(check(score[r1], score[r2])){
                score[r1] += 2; score[r2] -= 2;
                swap(room[i], room[i+1]);
            }
        }
        int p, q;
        for(int i=0; i<N; ++i){
            if(room[i]==0) p = i;
            if(room[i]==A) q = i;
        }
        if(abs(p-q)<=B){
            ++tot; ++con;
            maxcon = max(maxcon, con);
        }
        else con = 0;
    }
    cout << tot << " " << maxcon << endl;
}