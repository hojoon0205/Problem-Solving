#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a = 100, x, cnt=0;
    scanf("%lld", &x);
    while(a<x){
        a += a/100;
        ++cnt;
    }
    printf("%lld\n", cnt);
}