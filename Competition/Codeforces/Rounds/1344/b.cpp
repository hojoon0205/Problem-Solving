#include<bits/stdc++.h>
using namespace std;

int n, m;
char a[1010][1010];
bool chk[1010][1010];

void dfs(int r, int c){
    chk[r][c] = true;
    if(r>1 && a[r-1][c]=='#' && !chk[r-1][c]) dfs(r-1, c);
    if(r<n && a[r+1][c]=='#' && !chk[r+1][c]) dfs(r+1, c);
    if(c>1 && a[r][c-1]=='#' && !chk[r][c-1]) dfs(r, c-1);
    if(c<m && a[r][c+1]=='#' && !chk[r][c+1]) dfs(r, c+1);
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%s", a[i]+1);
    bool isvalid = true;
    int cr = 0;
    for(int i=1; i<=n; ++i){
        int l=m+1, r=0;
        for(int j=1; j<=m; ++j){
            if(a[i][j]=='.') continue;
            l = min(j, l);
            r = max(j, r);
        }
        if(l>r){ ++cr; }
        for(int j=l; j<=r; ++j){
            if(a[i][j]=='.'){
                isvalid = false;
                break;
            }
        }
    }
    int cc = 0;
    for(int j=1; j<=m; ++j){
        int l=n+1, r=0;
        for(int i=1; i<=n; ++i){
            if(a[i][j]=='.') continue;
            l = min(l, i);
            r = max(r, i);
        }
        if(l>r){ ++cc; }
        for(int i=l; i<=r; ++i){
            if(a[i][j]=='.'){
                isvalid = false;
                break;
            }
        }
    }
    if(cr+cc>0 && cr*cc==0) isvalid = false;
    if(!isvalid){
        printf("-1\n");
        return 0;
    }
    int ans = 0;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(chk[i][j] || a[i][j]=='.') continue;
            ++ans;
            dfs(i, j);
        }
    }
    printf("%d\n", ans);
}