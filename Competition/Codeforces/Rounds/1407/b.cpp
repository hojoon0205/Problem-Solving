#include<bits/stdc++.h>
using namespace std;

int gcd(int x, int y){ return y?gcd(y,x%y):x; }

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n; scanf("%d", &n);
        vector<int> a(n+1, 0);
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        int g = 0;
        for(int i=1; i<=n; ++i){
            int t = i;
            for(int j=i+1; j<=n; ++j){
                if(gcd(g,a[j]) > gcd(g, a[t])) t = j;
            }
            int tmp = a[t]; a[t] = a[i]; a[i] = tmp;
            g = gcd(g, a[i]);
        }
        for(int i=1; i<=n; ++i) printf("%d ", a[i]);
        printf("\n");
    }
}