#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n;
        vector<int> arr;
        scanf("%d", &n);
        vector<int> cnt(n+1, 0);
        vector<bool> chk(n+1, false);
        arr.push_back(0);
        for(int i=0; i<n; ++i){
            int x;
            scanf("%d", &x); arr.push_back(x);
            ++cnt[x];
        }
        for(int i=1; i<=n; ++i) arr[i] += arr[i-1];
        for(int l=1; l<n; ++l){
            for(int r=l+1; r<=n; ++r){
                int s = arr[r]-arr[l-1];
                if(s>n) break;
                chk[s] = true;
            }
        }
        int ans = 0;
        for(int i=1; i<=n; ++i){
            if(chk[i]) ans += cnt[i];
        }
        printf("%d\n", ans);
    }
}