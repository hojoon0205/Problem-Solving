#include<bits/stdc++.h>
using namespace std;

int n;
int arr[4][4];
bool chk[4][4];
int main()
{
    for(int i=1; i<=3; ++i){
        for(int j=1; j<=3; ++j){
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        int x;
        scanf("%d", &x);
        for(int j=1; j<=3; ++j){
            for(int k=1; k<=3; ++k){
                if(arr[j][k]==x){
                    chk[j][k] = true;
                }
            }
        }
    }
    for(int i=1; i<=3; ++i){
        if(chk[i][1]&&chk[i][2]&&chk[i][3]){
            printf("Yes"); return 0;
        }
        if(chk[1][i]&&chk[2][i]&&chk[3][i]){
            printf("Yes"); return 0;
        }
    }
    if(chk[1][1]&&chk[2][2]&&chk[3][3]){
        printf("Yes"); return 0;
    }
    if(chk[1][3]&&chk[2][2]&&chk[3][1]){
        printf("Yes"); return 0;
    }
    printf("No");
}