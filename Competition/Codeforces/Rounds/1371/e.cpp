#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, p;
    vector<int> a;
    scanf("%d%d", &n, &p);
    for(int i=1; i<=n; ++i){
        int x; scanf("%d", &x);
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int st = a[0];
    for(int i=1; i<n; ++i) st = max(st, a[i]-i);
    int c = 1, ed = a[n-1];
    for(int i=p-1; i<=n-1; ++i,++c){
        ed = min(ed, a[i]-c);
    }
    printf("%d\n", (ed-st+1)>0?(ed-st+1):0);
    for(int i=st; i<=ed; ++i) printf("%d ", i);
    printf("\n");
}