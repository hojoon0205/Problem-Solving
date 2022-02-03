#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int n=1; n<=11; ++n){
        cout << "n=" << n << "\n";

        vector<int> a(n); for(int i=0; i<n; ++i) a[i]=i+1;
        vector<int> cnt(n*n);
        do{
            int s=0;
            for(int i=0; i<n; ++i){
                s += max(i+1, a[i]);
            }
            ++cnt[s];
        }while(next_permutation(a.begin(), a.end()));
        for(int i=n*(n+1)/2; cnt[i]; ++i){
            cnt[i] += cnt[i-1];
            cout << cnt[i] << " ";
        }
        cout << "\n\n";
    }
}