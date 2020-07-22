#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int arr[100010];
int ans[100010];
int cnt[100010];
int new_cnt[100010];
stack<int> pos[100010];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n, s, b;
        scanf("%d", &n);
        scanf("%d%d", &s, &b);
        int ex = n - b;
        int sw = b - s;
        //memset(arr, 0, 4*n);
        //memset(ans, 0, 4*n);
        memset(cnt, 0, 4*(n+2));
        for(int i=1; i<=n+1; ++i){
            while(!pos[i].empty()) pos[i].pop();
        }
        //vector<stack<int>> pos(n+2, stack<int>());
        for(int i=1; i<=n; ++i){
            int tmp;
            scanf("%d", &tmp);
            arr[i-1] = tmp;
            ++cnt[tmp];
            pos[tmp].push(i-1);
        }
        int unused = 0;
        for(int i=1; i<=n+1; ++i){
            if(cnt[i]==0){ unused = i; break; }
        }

        priority_queue<pii> heap;
        for(int i=1; i<=n+1; ++i){
            heap.push({cnt[i],i});
        }
        int ss = s;
        while(ss){
            pii pi = heap.top();
            heap.pop();
            int count = pi.first;
            int color = pi.second;
            ans[pos[color].top()] = color;
            pos[color].pop();
            --cnt[color];
            heap.push({count-1, color});
            --ss;
        }
        if(heap.top().first < 0){
            printf("NO\n"); continue;
        }
        for(int i=1; i<=n+1; ++i) new_cnt[i] = cnt[i];
        while(ex){
            pii pi = heap.top();
            heap.pop();
            int count = pi.first;
            int color = pi.second;
            --new_cnt[color];
            ++new_cnt[unused];
            //pos[unused].push(pos[color].top());
            //pos[color].pop();
            heap.push({count-1, color});
            --ex;
        }
        if(heap.top().first < 0){
            printf("NO\n"); continue;
        }
        bool check = false;
        for(int i=1; i<=n+1; ++i){
            if(new_cnt[i] > n-s-cnt[i]){
                check = true;
                break;
            }
        }
        if(check){ printf("NO\n"); continue; }

        // for(int p=1,i=1; i<=n+1; ++i){
        //     if(new_cnt[i]==0) continue;
        //     while(new_cnt[i]){
        //         int x = 0;
        //         while(cnt[p]==0 || i==p){ ++x; ++p; if(p>n+1) p=1; }
        //         while(cnt[p] && new_cnt[i]){
        //             ans[pos[p].top()] = i;
        //             pos[p].pop();
        //             --new_cnt[i];
        //             --cnt[p];
        //         }
        //     }
        // }
        //printf("Case #%d: %d\n", tt, pos[unused].size());
        vector<pii> pl;
        for(int i=1; i<=n+1; ++i){
            while(!pos[i].empty()){
                pl.push_back({i,pos[i].top()});
                pos[i].pop();
            }
        }
        ss = pl.size();
        //printf("Case #%d\n", tt);
        //for(auto x : pl){ printf("%d %d\n", x.first, x.second); }
        for(int i=0; i<ss; ++i){
            ans[pl[(i+ss/2)%ss].second] = pl[i].first;
        }
        //for(int i=0; i<ss; ++i) ans[pl[i].second] = pl[i].first;
        ex = n-b;
        for(int i=0; i<ss; ++i){
            int po = pl[i].second;
            if(ans[po] == arr[po]){
                ans[po] = unused;
                --ex;
            }
        }
        for(int i=0; i<ss && ex; ++i){
            int po = pl[i].second;
            if(ans[po]==unused) continue;
            ans[po] = unused;
            --ex;
        }
        printf("YES\n");
        for(int i=0; i<n; ++i) printf("%d ", ans[i]);
        printf("\n");
    }
}