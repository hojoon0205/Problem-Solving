#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    int ma=-1, ma2=-1;
    for(int i=0; i<N; ++i){
        int x; cin >> x;
        if(x>ma){ ma2=ma; ma=x; }
        else if(x>ma2) ma2=x;
    }
    cout << ((ma-ma2 == 1 && ma%2!=N%2)?"Bob":"Alice") << endl;
}