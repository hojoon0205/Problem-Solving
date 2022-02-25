#include<bits/stdc++.h>
using namespace std;

int n;
char a[100100];
char b[100010];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        scanf("%d", &n);
        scanf("%s%s", a, b);
        int p = 0, inv = 0;
        vector<int> ans;
        for(int i=n-1; i>=0; --i){
            if((a[p]^inv) == b[i]){
                ans.push_back(1);
                ans.push_back(i+1);
            }
            else ans.push_back(i+1);
            inv ^= 1;
            p = n - inv - p;
        }
        printf("%d", ans.size());
        for(auto x : ans) printf(" %d", x);
        printf("\n");
    }
}