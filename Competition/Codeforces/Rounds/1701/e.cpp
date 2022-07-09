#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int N, M;
string A, B;
vector<vector<short>> fromB;
vector<vector<short>> fromF;
vector<vector<short>> come;
vector<vector<bool>> chk;

short fill_fromB(int i, int j){
    if(i==N && j==M) return fromB[i][j] = 0;
    if(i==N && j<M) return fromB[i][j] = 15000;
    if(i<N && j==M) return fromB[i][j] = N-i;
    if(chk[i][j]) return fromB[i][j];
    chk[i][j] = true;
    if(A[i]!=B[j]){
        fill_fromB(i+1,j);
        fromB[i][j] = fill_fromB(i+1,j)+1+come[i+1][j];
        return fromB[i][j];
    }
    fromB[i][j] = fill_fromB(i+1,j+1);
    come[i][j] = come[i+1][j+1]+1;
    return fromB[i][j];
}

short fill_fromF(int i, int j){
    if(i==0 && j==0) return fromF[i][j] = 0;
    if(i==0 && j>0) return fromF[i][j] = 15000;
    if(i>0 && j==0) return fromF[i][j] = 2*i;
    if(chk[i][j]) return fromF[i][j];
    chk[i][j] = true;
    if(A[i-1]!=B[j-1]){
        fill_fromF(i-1,j);
        fromF[i][j] = fill_fromF(i-1,j)+2+come[i-1][j];
        return fromF[i][j];
    }
    fromF[i][j] = fill_fromF(i-1,j-1);
    come[i][j] = come[i-1][j-1]+1;
    return fromF[i][j];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        cin >> N >> M;
        cin >> A >> B;
        fromB.clear(); fromF.clear(); come.clear(); chk.clear();
        fromB.resize(N+1, vector<short>(M+1, 15000));
        fromF.resize(N+1, vector<short>(M+1, 15000));
        come.resize(N+1, vector<short>(M+1, 0));
        chk.resize(N+1, vector<bool>(M+1, false));
        for(int i=0; i<=N; ++i){
            for(int j=0; j<=M; ++j) fill_fromB(i,j);
        }
        come.clear(); chk.clear();
        come.resize(N+1, vector<short>(M+1, 0));
        chk.resize(N+1, vector<bool>(M+1, false));
        for(int i=0; i<=N; ++i){
            for(int j=0; j<=M; ++j) fill_fromF(i,j);
        }
        int ans = min(fromB[0][0], (short)(fromF[N][M]+1));
        // cout << "B(0,0): " << fill_fromB(0,0) << endl;
        // cout << "F(N,M): " << fill_fromF(N,M) << endl;
        // for(int i=0; i<=N; ++i){
        //     for(int j=0; j<=M; ++j) cout << comeB[i][j] << " ";
        //     cout << endl;
        // }
        for(int i=0; i<=N; ++i){
            for(int j=0; j<=M; ++j){
                if(ans > 1 + fromF[i][j] + fromB[i][j]){
                    ans = 1 + fromF[i][j] + fromB[i][j];
                }
            }
        }
        cout << (ans>=15000?-1:ans) << endl;
    }
}