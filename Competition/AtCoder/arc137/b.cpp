#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<int> a(N+1);
    vector<int> su(N+1, 0);
    for(int i=1; i<=N; ++i){
        cin >> a[i];
        su[i] = su[i-1] + (a[i]?-1:1);
    }
    int mad=0, mid=0, ma=0, mi=0;
    for(int i=1; i<=N; ++i){
        mad = max(mad, su[i]-mi);
        mid = min(mid, su[i]-ma);
        mi = min(su[i], mi);
        ma = max(su[i], ma);
    }
    //cout << mad << endl << mid << endl;
    cout << mad-mid+1 << endl;
}