#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<int> b, a, x;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        int t;
        scanf("%d", &t);
        b.push_back(t);
    }
    x.push_back(0);
    for(int i=0; i<n; ++i){
        a.push_back(b[i] + x[i]);
        x.push_back(max(x[i],a[i]));
    }
    for(auto t : a){
        printf("%d ", t);
    }
    printf("\n");
}