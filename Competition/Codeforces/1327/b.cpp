#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(;t--;){
        int n;
        scanf("%d", &n);
        vector<vector<int>> L;
        vector<bool> chk(n, false);
        vector<int> match(n, -1);
        int cnt = 0;
        for(int i=0; i<n; ++i){
            L.push_back(vector<int>());
            int si;
            scanf("%d", &si);
            for(;si--;){
                int x;
                scanf("%d", &x);
                L[i].push_back(x);
            }
            for(auto x : L[i]){
                if(chk[x-1]) continue;
                ++cnt;
                chk[x-1] = true;
                match[i] = x; break;
            }
        }
        if(cnt == n){ printf("OPTIMAL\n"); continue; }
        int a, b;
        for(a=0; a<n; ++a) if(match[a]<0) break;
        for(b=0; b<n; ++b) if(chk[b]==false) break;
        printf("IMPROVE\n%d %d\n", a+1, b+1);
    }
}