#include<bits/stdc++.h>
using namespace std;

int n, m;
char arr[110][110];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%s", arr[i]+1);
    int si=0, sj=0, ei=0, ej=0;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(arr[i][j]=='#'){
                if(!(si+sj)) si=i,sj=j;
                ei=i; ej=j;
            }
        }
    }
    //UP
    for(int i=sj; i<=ej; ++i){
        if(arr[si][i]=='.'){
            printf("UP\n");
            return 0;
        }
    }
    //DOWN
    for(int i=sj; i<=ej; ++i){
        if(arr[ei][i]=='.'){
            printf("DOWN\n");
            return 0;
        }
    }
    //LEFT
    for(int i=si; i<=ei; ++i){
        if(arr[i][sj]=='.'){
            printf("LEFT\n");
            return 0;
        }
    }
    //RIGHT
    for(int i=si; i<=ei; ++i){
        if(arr[i][ej]=='.'){
            printf("RIGHT\n");
            return 0;
        }
    }
}