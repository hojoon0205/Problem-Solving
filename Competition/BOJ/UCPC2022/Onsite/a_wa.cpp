#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;

ll a[3010][3010][3];
ll col[3010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N; cin >> N;
    for(int i=1; i<=N; ++i) cin >> col[i];
    for(int i=1; i<N; ++i){
        if(col[i]==col[i+1]){
            cout << "0\n";
            return 0;
        }
    }
    if(N==2){ cout << "1\n"; return 0; }
    a[3][2][0] = 1;
    a[3][2][1] = (col[3]==col[1]?0:2);
    a[3][2][2] = (col[3]==col[1]?0:1);
    for(int i=4; i<=N; ++i){
        a[i][i-1][0] = 1;
        a[i][i-1][1] = (col[i]==col[i-2]?0:2);
        a[i][i-1][2] = (col[i]==col[i-2]?0:1);
        for(int j=i-2; j>=2; --j){
            a[i][j][2] = (col[i]==col[j-1]?0:a[i][j+1][2]);
            a[i][j][1] = (col[i]==col[j-1]?0:((a[i][j+1][2]*2 + a[i][j+1][1]*2)%MOD));
            a[i][j][0] = ((a[i][j+1][2] + a[i][j+1][1]*2 + a[i][j+1][0]*4)%MOD);
        }
    }
    /*
    for(int i=3; i<=N; ++i){
        cout << "i=" << i << endl;
        for(int j=2; j<=i-1; ++j){
            cout << "j=" << j << ":";
            cout << "{" << a[i][j][0] << "," << a[i][j][1] << "," << a[i][j][2] << "} ";
        }
        cout << endl;
    }
    */
    cout << (a[N][2][0]+a[N][2][1]+a[N][2][2])%MOD << endl;
}