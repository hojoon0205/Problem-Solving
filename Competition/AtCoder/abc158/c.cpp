#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int a, b, n;
    cin >> a >> b;
    for(n=1; n<=100000; ++n){
        if(n*8/100 == a && n/10==b){
            printf("%d\n", n);
            return 0;
        }
    }
    printf("-1\n");
}