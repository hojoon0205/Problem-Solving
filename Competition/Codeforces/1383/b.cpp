#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n, s = 0;
        scanf("%d", &n);
        vector<int> arr;
        for(int i=0; i<n; ++i){
            int x;
            scanf("%d", &x);
            arr.push_back(x);
            s ^= x;
        }
        if(s==0){
            printf("DRAW\n");
            continue;
        }
        int c = 1;
        while(s){
            if(c&s) s ^= c;
            if(s==0) break;
            c<<=1;
        }
        int k = 0;
        for(auto x : arr) k += (x&c)?1:0;
        if(k%4==1){ printf("WIN\n"); continue; }
        if(n%2==1){ printf("LOSE\n"); continue; }
        else printf("WIN\n");
    }
}