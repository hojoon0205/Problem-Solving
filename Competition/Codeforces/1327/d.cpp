#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> T;
vector<int> p;
vector<int> color;

bool check(vector<int> &period, int k){
    int L = period.size();
    vector<bool> chk(L, false);
    for(int i=0; i<k; ++i){ // start at period[i]
        int x = i, c = color[period[i]];
        bool sw = true;
        while(!chk[x]){
            chk[x] = true;
            if(c != color[period[x]]) sw = false;
            x = (x+k)%L;
        }
        if(sw) return true;
    }
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(;t--;){
        scanf("%d", &n);
        T.clear(); p.clear(); color.clear();
        for(int i=1; i<=n; ++i){ int x; scanf("%d", &x); p.push_back(x-1); }
        for(int i=1; i<=n; ++i){ int x; scanf("%d", &x); color.push_back(x); }
        vector<bool> chk(n, false);
        int tc = 0;
        for(int i=0; i<n; ++i){
            if(chk[i]) continue;
            T.push_back(vector<int>());
            ++tc;
            int x = i;
            while(!chk[x]){
                chk[x] = true;
                T[tc-1].push_back(x);
                x = p[x];
            }
        }
        int ans = n;
        for(auto &period : T){
            int L = period.size();
            for(int d=1; d*d<=L; ++d){
                if(L%d || d>ans) continue;
                if(check(period, d)) ans = min(ans, d);
                if(check(period, L/d)) ans = min(ans, L/d);
            }
        }
        printf("%d\n", ans);
    }
}