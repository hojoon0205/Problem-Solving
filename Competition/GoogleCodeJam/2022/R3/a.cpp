#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T, N, K;
    cin >> T >> N >> K;
    for(int tt=1; tt<=T; ++tt){
        int mode = 0;
        while(mode==0){
            vector<int> arr(N);
            for(int i=0; i<N; ++i) cin >> arr[i];
            vector<int> col(N, -1);
            
            int c = 0;
            for(int i=0; i<N; ++i){
                if(arr[i]==i+1) col[i] = ++c;
            }
            for(int i=0; i<N; ++i){
                if(col[i] >= 0) continue;
                int l=1;
                for(int p=arr[i]-1; p!=i; p=arr[p]-1, ++l);
                if(l<=34){
                    ++c;
                    col[i] = c;
                    for(int p=arr[i]-1; p!=i; p=arr[p]-1, ++l) col[p] = c;
                }
            }
            for(int i=0; i<N; ++i){
                if(col[i] >= 0) continue;
                ++c;
                int j;
                for(j=0; j<N; ++j){
                    if(arr[j]==i+1) break;
                }
                if(col[j] < 0) col[i] = col[j] = c;
                else{
                    j = arr[i]-1;
                    if(col[j] < 0) col[i] = col[j] = c;
                }
            }
            ++c;
            for(int i=0; i<N; ++i){
                if(col[i] < 0) col[i] = c;
            }

            for(int i=0; i<N; ++i) cout << col[i] << " ";
            cout << endl;
            cin >> mode;
        }
        if(mode<0) return 0;
    }
}