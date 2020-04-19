#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    for(;T--;){
        char str[100010];
        scanf("%s", str);
        int n = strlen(str), c=0;
        for(int i=0; i<n; ++i) c += str[i]-'0';
        if(c%3){  printf("cyan\n"); continue; }
        int cnt0 = 0, cnte = 0;
        for(int i=0; i<n; ++i){
            if(str[i]-'0' == 0){ ++cnt0; }
            if((str[i]-'0')%2 == 0) ++cnte;
        }
        if(cnte<2 || cnt0==0){ printf("cyan\n"); continue; }
        printf("red\n");
    }
}