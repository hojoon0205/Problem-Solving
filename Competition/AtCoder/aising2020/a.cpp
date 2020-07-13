#include<bits/stdc++.h>
using namespace std;

int main()
{
    int L, R, D;
    scanf("%d%d%d", &L, &R, &D);
    printf("%d\n", R/D - (L-1)/D);
}