#include<bits/stdc++.h>
using namespace std;

int n;
int Map[1010][1010]; // 0:none 1:up 2:down 3:left 4:right 5:X 6:notX
char ans[1010][1010];
int dest[1010][1010][2];
int q[1000010][2]; //r, c

int main()
{
    int f=0, r=0;
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            scanf("%d%d", &dest[i][j][0], &dest[i][j][1]);
            if(dest[i][j][0]>0){
                if(i == dest[i][j][0] && j == dest[i][j][1]){
                    if(Map[i][j]!=5 && Map[i][j]!=0){
                        printf("INVALID\n");
                        return 0;
                    }
                    else Map[i][j] = 5;
                }
                else{
                    if(Map[dest[i][j][0]][dest[i][j][1]]%5 != 0){
                        printf("INVALID\n");
                        return 0;
                    }
                    Map[dest[i][j][0]][dest[i][j][1]] = 5;
                    Map[i][j] = 6;
                }
            }
            else Map[i][j] = 6;
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(Map[i][j]==5){
                ++r;
                q[r][0] = i; q[r][1] = j;
            }
        }
    }
    while(f<r){
        ++f;
        int R = q[f][0], C = q[f][1];
        if(R>1 && (Map[R-1][C]==0 || Map[R-1][C]==6) && dest[R-1][C][0]==dest[R][C][0] && dest[R-1][C][1]==dest[R][C][1]){
            ++r;
            q[r][0] = R-1; q[r][1] = C;
            Map[R-1][C] = 2;
        }
        if(R<n && (Map[R+1][C]==0 || Map[R+1][C]==6) && dest[R+1][C][0]==dest[R][C][0] && dest[R+1][C][1]==dest[R][C][1]){
            ++r;
            q[r][0] = R+1; q[r][1] = C;
            Map[R+1][C] = 1;
        }
        if(C>1 && (Map[R][C-1]==0 || Map[R][C-1]==6) && dest[R][C-1][0]==dest[R][C][0] && dest[R][C-1][1]==dest[R][C][1]){
            ++r;
            q[r][0] = R; q[r][1] = C-1;
            Map[R][C-1] = 4;
        }
        if(C<n && (Map[R][C+1]==0 || Map[R][C+1]==6) && dest[R][C+1][0]==dest[R][C][0] && dest[R][C+1][1]==dest[R][C][1]){
            ++r;
            q[r][0] = R; q[r][1] = C+1;
            Map[R][C+1] = 3;
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(dest[i][j][0]>0 && (Map[i][j]==0 || Map[i][j]==6)){
                printf("INVALID\n");
                return 0;
            }
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(dest[i][j][0]>0) continue;
            if(Map[i][j]%6 != 0) continue;
            int cc = 0;
            if(i==1 || (i>1 && dest[i-1][j][0]>0)) ++cc;
            if(i==n || (i<n && dest[i+1][j][0]>0)) ++cc;
            if(j==1 || (j>1 && dest[i][j-1][0]>0)) ++cc;
            if(j==n || (j<n && dest[i][j+1][0]>0)) ++cc;
            if(cc==4){ printf("INVALID\n"); return 0; }

            if(i>1 && dest[i-1][j][0]==-1 && Map[i-1][j]%6==0){
                Map[i-1][j] = 2; Map[i][j] = 1; continue;
            }
            if(i<n && dest[i+1][j][0]==-1 && Map[i+1][j]%6==0){
                Map[i+1][j] = 1; Map[i][j] = 2; continue;
            }
            if(j>1 && dest[i][j-1][0]==-1 && Map[i][j-1]%6==0){
                Map[i][j-1] = 4; Map[i][j] = 3; continue;
            }
            if(j<n && dest[i][j+1][0]==-1 && Map[i][j+1]%6==0){
                Map[i][j+1] = 3; Map[i][j] = 4; continue;
            }

            if(i>1 && dest[i-1][j][0]==-1 && Map[i-1][j]%6){ Map[i][j] = 1; continue; }
            if(i<n && dest[i+1][j][0]==-1 && Map[i+1][j]%6){ Map[i][j] = 2; continue; }
            if(j>1 && dest[i][j-1][0]==-1 && Map[i][j-1]%6){ Map[i][j] = 3; continue; }
            if(j<n && dest[i][j+1][0]==-1 && Map[i][j+1]%6){ Map[i][j] = 4; continue; }
        }
    }

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(Map[i][j]%6==0){
                printf("INVALID\n");
                return 0;
            }
        }
    }

    printf("VALID\n");
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(Map[i][j]==1) ans[i][j] = 'U';
            if(Map[i][j]==2) ans[i][j] = 'D';
            if(Map[i][j]==3) ans[i][j] = 'L';
            if(Map[i][j]==4) ans[i][j] = 'R';
            if(Map[i][j]==5) ans[i][j] = 'X';
        }
        ans[i][n+1]=0;
        printf("%s\n", ans[i]+1);
    }
}