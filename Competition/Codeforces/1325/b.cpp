#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for(;T--;){
        int n;
        vector<int> V;
        scanf("%d", &n);
        for(;n--;){
            int x;
            scanf("%d", &x);
            V.push_back(x);
        }
        sort(V.begin(), V.end());
        V.erase(unique(V.begin(), V.end()), V.end());
        printf("%d\n", V.size());
    }
}