#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n;
        vector<int> a;
        vector<bool> chk;
        scanf("%d", &n);
        chk = vector<bool>(n, false);
        for(int i=0; i<n; ++i){ int x;scanf("%d", &x); a.push_back(x); }
        for(int i=0; i<n; ++i){
            a[i] = (a[i]%n + n)%n;
        }
        bool ans = true;
        for(int i=0; i<n; ++i){
            int x = (i + a[i])%n;
            if(chk[x]){
                ans = false;
                break;
            }
            chk[x] = true;
        }
        printf("%s\n", ans?"YES":"NO");
    }
}