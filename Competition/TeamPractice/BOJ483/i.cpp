#include<bits/stdc++.h>
using namespace std;

int n, q;
int s[2050][2050];
int tree[4100][4100];

int main()
{
    scanf("%d%d", &n, &q);
    for(;n--;){
        int r1, r2, c1, c2;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2); // [r1,r2), [c1,c2)
        s[r1][c1] += 1;
        s[r2][c2] += 1;
        s[r1][c2] += -1;
        s[r2][c1] += -1;
    }
    for(int i=1; i<=1500; ++i) s[0][i] += s[0][i-1], s[i][0] += s[i-1][0];
    for(int i=1; i<=1500; ++i){
        for(int j=1; j<=1500; ++j){
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }
    int S = 2048;
    for(int i=0; i<1500; ++i){
        for(int j=0; j<1500; ++j)
            tree[S+i][S+j] = s[i][j];
        for(int j=S-1; j>=1; --j) tree[S+i][j] = max(tree[S+i][j*2], tree[S+i][j*2+1]);
    }
    for(int j=0; j<1500; ++j){
        for(int i=S-1; i>=1; --i) tree[i][S+j] = max(tree[i*2][S+j], tree[i*2+1][S+j]);
    }
    for(int i=S-1; i>=1; --i){
        for(int j=S-1; j>=1; --j){
            tree[i][j] = max(tree[i*2][j], tree[i*2+1][j]);
        }
    }
    for(;q--;){
        int r1, r2, c1, c2;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2); --r2; --c2;
        vector<int> rs, cs;
        r1+=S; r2+=S; c1+=S; c2+=S;
        while(r1<r2){
            if(r1%2 == 1){ rs.push_back(r1); ++r1; }
            if(r2%2 == 0){ rs.push_back(r2); --r2; }
            r1>>=1; r2>>=1;
        }
        if(r1==r2) rs.push_back(r1);
        while(c1<c2){
            if(c1%2 == 1){ cs.push_back(c1); ++c1; }
            if(c2%2 == 0){ cs.push_back(c2); --c2; }
            c1>>=1; c2>>=1;
        }
        if(c1==c2) cs.push_back(c1);
        int ans = 0;
        for(auto r : rs){
            for(auto c : cs){
                ans = max(ans, tree[r][c]);
            }
        }
        printf("%d\n", ans);
    }
}