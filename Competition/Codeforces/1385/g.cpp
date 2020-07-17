#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n;
        scanf("%d", &n);
        vector<int> cnt(n+1);
        vector<vector<int>> a(2, vector<int>(n+1));
        for(int i=1; i<=n; ++i){
            scanf("%d", &a[0][i]);
            ++cnt[a[0][i]];
        }
        for(int i=1; i<=n; ++i){
            scanf("%d", &a[1][i]);
            ++cnt[a[1][i]];
        }
        bool sw = true;
        for(int i=1; i<=n; ++i){
            if(cnt[i]!=2){
                printf("-1\n");
                sw = false;
                break;
            }
        }
        if(!sw) continue;
        
        vector<pii> idx(n+1, {0,0});
        for(int i=0; i<2; ++i){
            for(int j=1; j<=n; ++j){
                int x = a[i][j];
                if(idx[x].first) idx[x].second = j;
                else idx[x].first = j;
            }
        }
        vector<int> status(n+1, 0);
        for(int i=0; i<2; ++i){
            for(int j=1; j<=n; ++j) status[a[i][j]] += i;
        }
        vector<bool> chk(n+1, false);
        int ans = 0;
        vector<int> li;
        for(int i=1; i<=n; ++i){
            if(status[i]==1) continue;
            int cyclen = 0, cur = idx[i].first, val = i, c=0;
            vector<int> c1, c2;
            while(!chk[cur]){
                chk[cur] = true;
                if(status[val]!=1){
                    ++status[a[0][cur]]; --status[a[1][cur]];
                    int tmp = a[0][cur]; a[0][cur] = a[1][cur]; a[1][cur] = tmp;
                    c1.push_back(cur);
                }
                else c2.push_back(cur);
                val = a[0][cur] + a[1][cur] - val;
                cur = idx[val].first + idx[val].second - cur;
                ++cyclen;
            }
            ans += min(c1.size(), c2.size());
            if(c1.size() < c2.size()){
                for(auto x : c1) li.push_back(x);
            }
            else{
                for(auto x : c2) li.push_back(x);
            }
        }
        printf("%d\n", ans);
        for(auto x : li) printf("%d ", x);
        printf("\n");
    }
}