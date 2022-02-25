#include<bits/stdc++.h>
using namespace std;

int s[100010];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i) scanf("%d", &s[i]);
    vector<int> boxes(k,0);
    for(int i=n; i>n-k && i>0; --i) boxes[n-i] = s[i];
    for(int i=n-k; i>=1; --i) boxes[k-1+(i-n+k)] += s[i];
    int ans = 0;
    for(int i=0; i<k; ++i) ans = max(ans, boxes[i]);
    printf("%d\n", ans);
}