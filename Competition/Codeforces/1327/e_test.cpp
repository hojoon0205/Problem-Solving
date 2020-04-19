#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int M = 1;
    for(int N=1; N<=n; ++N){
        M *= 10;
        vector<int> cnt(N, 0);
        for(int i=0; i<M; ++i){
            int X = i;
            int bef = X%10, con=1;
            for(int c=1; c<=N; ++c){
                X/=10;
                int cur = c==N?-1:X%10;
                if(bef != cur){ cnt[con-1] += 1; con = 1; }
                else ++con;
            }
        }
        for(auto x : cnt){ printf("%d ", x); }
        printf("\n");
    }
}