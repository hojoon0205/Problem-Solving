#include<bits/stdc++.h>
using namespace std;

int N, M;
set<int> Qlist[100010];
pair<int,int> Wlist[100010];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; ++i){
        int f, s;
        scanf("%d%d", &f, &s);
        Wlist[i] = {f,s};
        Qlist[f].insert(i);
        if(Qlist[f].size()!=1) Qlist[s].insert(i);
    }
    int ans = 0;
    for(int i=1; i<=M; ++i){
        ans += Qlist[i].empty()?0:1;
    }
    printf("%d\n", ans);
    // for(int j=1; j<=M; ++j){
    //     printf("%d: ", j);
    //     for(auto x : Qlist[j]){
    //         printf("%d ", x);
    //     }
    //     printf("\n");
    // }
    // printf("\n\n");
    for(int i=0; i<N-1; ++i){
        int f = Wlist[i].first, s = Wlist[i].second;
        int newf = i;
        while(Qlist[f].find(newf) != Qlist[f].end()){
            Qlist[f].erase(newf);
            if(Qlist[f].empty()){ --ans; break; }
            newf = *Qlist[f].begin();
            int w1 = Wlist[newf].first;
            int w2 = Wlist[newf].second;
            if(f != w1) break;
            else f = w2;
        }
        printf("%d\n", ans);
        // for(int j=1; j<=M; ++j){
        //     printf("%d: ", j);
        //     for(auto x : Qlist[j]){
        //         printf("%d ", x);
        //     }
        //     printf("\n");
        // }
        // printf("\n\n");
    }
}