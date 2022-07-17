#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int ur[2020][2020];
int row[2020][2020], jrow[2020][2020];
int col[2020][2020], jcol[2020][2020];
char A[2020][2020];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        int N; cin >> N;
        for(int i=0; i<N; ++i) cin >> A[i];
        for(int i=0; i<=N; ++i){
            for(int j=0; j<=N; ++j) row[i][j] = col[i][j] = ur[i][j] = 0;
        }
        ll ans = 0;
        for(int i=1; i<N; ++i){
            for(int j=N-2; j>=0; --j){
                ur[i][j] = ur[i-1][j] + ur[i][j+1] - ur[i-1][j+1] + (A[i-1][j+1]=='.'?1:0);
                if(A[i][j]=='.') ans += (ll)ur[i][j];
            }
        }
        for(int i=0; i<N; ++i){
            int c = 0, d = 0;
            for(int j=N-1; j>=0; --j){
                if(A[i][j]=='#') { c += d; d = 0; }
                else d += 1;
                row[i][j] = c;
            }
            c=N;
            for(int j=N-1; j>=0; --j){
                if(A[i][j]=='#') c=j, jrow[i][j] = -1;
                if(A[i][j]=='.') jrow[i][j] = c;
            }
        }
        for(int j=0; j<N; ++j){
            int c = 0, d = 0;
            for(int i=N-1; i>=0; --i){
                if(A[i][j]=='#') { c += d; d = 0; }
                else d += 1;
                col[i][j] = c;
            }
            c=N;
            for(int i=N-1; i>=0; --i){
                if(A[i][j]=='#') c=i, jcol[i][j] = -1;
                if(A[i][j]=='.') jcol[i][j] = c;
            }
        }
        for(int i=N-1; i>=0; --i){
            for(int j=N-1; j>=0; --j){
                row[i][j] += row[i+1][jrow[i][j]-1];
                col[i][j] += col[jcol[i][j]-1][j+1];
                if(A[i][j]=='.') ans += (ll)(row[i][j] + col[i][j]);
            }
        }
        cout << "Case #" << tt << "\n";
        /*
        cout << "Upper Right\n";
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j) cout << ur[i][j] << (j==N-1?'\n':' ');
        }
        cout << "Row\n";
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j) cout << row[i][j] << (j==N-1?'\n':' ');
        }
        cout << "Col\n";
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j) cout << col[i][j] << (j==N-1?'\n':' ');
        }
        */
        cout << ans << "\n";
    }
}