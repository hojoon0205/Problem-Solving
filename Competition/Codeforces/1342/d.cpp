#include<bits/stdc++.h>
using namespace std;

vector<int> m;
int c[200010];
set<pair<int,int>> S;
vector<int> ans[200010];
int nc;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; ++i){
        int x; scanf("%d", &x);
        m.push_back(x);
    }
    sort(m.begin(), m.end());
    for(int i=1; i<=k; ++i) scanf("%d", &c[i]);
    for(int i=n-1; i>=0; --i){
        int X = m[i];
        auto p = S.upper_bound(make_pair(c[X],0));
        //printf("%d %d\n", X, c[X]);
        //printf("%d %d\n\n", p->first, p->second);
        if(S.size()==0 || p == S.begin()){
            ++nc;
            ans[nc].push_back(X);
            S.insert(make_pair(1, nc));
        }
        else{
            --p;
            int t = p->second;
            ans[t].push_back(X);
            S.erase(p);
            S.insert(make_pair(ans[t].size(), t));
        }
    }
    printf("%d\n", nc);
    for(int i=1; i<=nc; ++i){
        printf("%d", ans[i].size());
        for(int j=0; j<ans[i].size(); ++j) printf(" %d", ans[i][j]);
        printf("\n");
    }
}