#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define fi first
#define se second

double p[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0; i<10; ++i) cin >> p[i];
    sort(p, p+10);
    double ans = 1e9 / 362880.0;
    for(int i=9; i>=1; --i) ans *= p[i];
    cout << fixed;
    cout.precision(12);
    cout << ans << endl;
}