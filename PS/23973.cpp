#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M; cin >> N >> M;
    vector<string> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(A[i][j]!='1') continue;
            //center is (i,j)
            vector<int> cnt(10);
            for(int t=-9; t<=9; ++t){
                for(int k=-9; k<=9; ++k){
                    int x = i+t, y = j+k;
                    if(x<0 || y<0 || x>=N || y>=M) continue;
                    if(A[x][y]!='1') continue;
                    ++cnt[ max(abs(t), abs(k)) ];
                }
            }
            bool isans = true;
            for(int x=0; x<10 && isans; ++x){
                if(cnt[x]!=1) isans=false;
            }
            if(isans){ cout << i << " " << j << endl; return 0;}
        }
    }
    cout << "-1\n";
}