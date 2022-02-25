#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    scanf("%d", &n);
    for(;n--;){
        int d;
        scanf("%d", &d);
        vector<int> ans;
        int t=1;
        while(t<=d){
            t*=10;
            if(d%t == 0) continue;
            ans.push_back(d%t);
            d -= d%t;
        }
        printf("%d\n", ans.size());
        for(auto x : ans) printf("%d ", x);
        printf("\n");
    }
}