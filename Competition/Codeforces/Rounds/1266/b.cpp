#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    for(;t--;){
        long long x;
        scanf("%lld", &x);
        printf("%s\n", (x>14 && x%14<=6 && x%14>=1)?"YES":"NO");
    }
}