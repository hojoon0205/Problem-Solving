#include<bits/stdc++.h>
using namespace std;

using ld = long double;

int n, k;
ld p;

typedef struct matrix{
    int sz;
    vector<vector<ld>> mat;
    matrix(int _n){
        sz = _n;
        mat.resize(_n, vector<ld>(_n, 0.0));
    }
    struct matrix operator*(struct matrix &a){
        struct matrix ret(sz);
        for(int i=0; i<sz; ++i){
            for(int j=0; j<sz; ++j){
                for(int k=0; k<sz; ++k){
                    ret.mat[i][j] += mat[i][k] * a.mat[k][j];
                }
            }
        }
        return ret;
    }
}Matrix;

int main()
{
    cin >> n >> k;
    cin >> p;
    cout << fixed;
    cout.precision(12);
    Matrix a((1<<n) + 3);
    int mask = (1<<n)-1;
    for(int i=0; i<(1<<n); ++i){
        //a.mat[j][i] : i에서 j로 갈 확률
        int cnt = 0;
        for(int t=1; t<(1<<n); t<<=1) cnt += (i&t?1:0);
        if(cnt>=k){ a.mat[(1<<n)][i] = 1.0; continue; }
        int x = mask&(i<<1);
        a.mat[x][i] = 1.0 - p;
        x ^= 1;
        a.mat[x][i] = p;
    }
    a.mat[(1<<n)+1][(1<<n)] = a.mat[(1<<n)+1][(1<<n)+1] = 1.0;
    a.mat[(1<<n)+2][(1<<n)+1] = a.mat[(1<<n)+2][(1<<n)+2] = 1.0;
    /*
    for(int i=0; i<(1<<n); ++i){
        for(int j=0; j<(1<<n); ++j) cout << a.mat[i][j] << " ";
        cout << endl;
    }
    */
    for(int i=0; i<40; ++i){
        a = a*a;
    }
    cout << (1LL<<40)-2 - a.mat[(1<<n)+2][0] << endl;
    //cout << P << endl;
    //cout << (1.0/P) << endl;
}