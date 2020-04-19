#include<bits/stdc++.h>
using namespace std;

int arr[20][1010];
int cnt[20][1010];

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            scanf("%1d", &arr[i][j]);
            cnt[i][j] = cnt[i-1][j] + arr[i][j];
        }
    }
    int ans = n+m;
    for(int rcut=0; rcut<(1<<(n-1)); ++rcut){
        vector<int> row_cut;
        row_cut.push_back(0);
        for(int tmp = rcut, i=1; tmp; tmp>>=1, ++i){
            if(tmp&1) row_cut.push_back(i);
        }
        int count = row_cut.size()-1, rcnt = row_cut.size();
        vector<int> whites;
        for(int i=0; i<rcnt; ++i) whites.push_back(0);
        row_cut.push_back(n);
        if(count > ans) continue;
        bool possible = true;
        for(int j=1; j<=m; ++j){
            bool sw = false;
            for(int i=0; i<row_cut.size()-1; ++i){
                // row_cut[i] ~ row_cut[i+1]
                if(cnt[row_cut[i+1]][j] - cnt[row_cut[i]][j] > k) possible = false;
                if(whites[i] + cnt[row_cut[i+1]][j] - cnt[row_cut[i]][j] > k){ sw = true; break; }
            }
            if(sw){
                ++count;
                for(int i=0; i<row_cut.size()-1; ++i) whites[i] = 0;
            }
            for(int i=0; i<row_cut.size()-1; ++i){
                whites[i] += cnt[row_cut[i+1]][j] - cnt[row_cut[i]][j];
            }
        }
        if(possible) ans = min(ans, count);
    }
    printf("%d\n", ans);
}