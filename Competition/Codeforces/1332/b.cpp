#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt, T;
    int p[12] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int N;
        vector<int> arr;
        vector<int> ans;
        vector<bool> chk(12);
        int c[12];
        int m = 0;
        scanf("%d", &N);
        for(int i=0; i<N; ++i){ int x; scanf("%d", &x); arr.push_back(x); }
        for(int i=0; i<N; ++i){
            for(int j=1; j<=11; ++j){
                if(arr[i]%p[j]) continue;
                ans.push_back(j);
                if(chk[j]==false){
                    ++m;
                    c[j] = m;
                }
                chk[j] = true;
                break;
            }
        }
        printf("%d\n", m);
        for(auto x : ans) printf("%d ", c[x]);
        printf("\n");
    }
}