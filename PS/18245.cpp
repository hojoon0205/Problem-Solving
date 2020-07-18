#include<bits/stdc++.h>
using namespace std;

char str[100010];

int main()
{
    int c = 0;
    while(1){
        scanf("%s", str);
        ++c;
        if(str[1]=='a') break;
        int l = strlen(str);
        for(int i=0; i<l; i+=c+1) printf("%c", str[i]);
        printf("\n");
    }
}