#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(;t--;){
        int x;
        scanf("%d", &x);
        if(x==1){ printf("-1\n"); continue; }
        for(int i=1; i<x; ++i) printf("5");
        printf("4\n");
    }
}