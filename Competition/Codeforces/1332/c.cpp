#include<bits/stdc++.h>
using namespace std;

char str[200010];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int N, k;
        scanf("%d%d", &N, &k);
        scanf("%s", str);
        int ans = 0;
        for(int j=0; j<(k+1)/2; ++j){
            vector<int> cnt(26,0);
            int c = 0;
            for(int i=0; i<N/k; ++i){
                int l = i*k+j, r = (i+1)*k-j-1;
                ++cnt[str[l]-'a']; ++c;
                if(l!=r){ ++cnt[str[r]-'a']; ++c; }
            }
            int m = 0;
            for(auto x : cnt) m = max(m, x);
            ans += c-m;
        }
        printf("%d\n", ans);
    }
}