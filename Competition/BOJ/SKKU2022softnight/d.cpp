#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;

    int l = 1, r = N;
    while(true){
        int m = (l+r)/2;
        cout << "? " << m << endl;
        int s; cin >> s;
        s = s - (m-s);
        if(s==0){ cout << "! " << m << endl; break; }
        else if(s<0){ r = m-1; }
        else l = m+1;
    }
}