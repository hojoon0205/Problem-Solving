#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<int> a(1<<N);
    for(int i=0; i<(1<<N); ++i) cin >> a[i];

    for(int i=0; i<(1<<N); ++i){
        for(int x=1; x<(1<<N); x<<=1){
            if(i&x) continue;
            for(int y=1; y<(1<<N); y<<=1){
                if(i&y || x==y) continue;
                if(a[i|x]+a[i|y] < a[i]+a[i|x|y]){
                    cout << (i|x) << " " << (i|y) << endl;
                    return 0;
                }
            }
        }
    }
    cout << "-1" << endl;

}