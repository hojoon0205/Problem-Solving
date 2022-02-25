#include<bits/stdc++.h>
using namespace std;

char str[500];

int main()
{
    int T;
    scanf("%d", &T);
    for(;T--;){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        memset(str, 0, sizeof(str));
        if(b==0){
            if(a) for(int i=0; i<=a; ++i) str[i] = '0';
            if(c) for(int i=0; i<=c; ++i) str[i] = '1';
            printf("%s\n", str);
            continue;
        }
        int p = 0; --b;
        for(int i=0; i<=a; ++i) str[p++] = '0';
        for(int i=0; i<=c; ++i) str[p++] = '1';
        for(int i=0; i<b; ++i) str[p++] = '0' + (i%2);
        printf("%s\n", str);
    }
}