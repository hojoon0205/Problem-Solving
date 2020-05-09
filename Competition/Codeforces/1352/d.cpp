#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n, a=0, b=0;
        scanf("%d", &n);
        vector<int> arr;
        for(int i=1; i<=n; ++i){
            int x;
            scanf("%d", &x); arr.push_back(x);
        }
        int l=0, r=n-1, turn=1, moves=0, pa=0, pb=0;
        while(l<=r){
            if(turn){ // Alice
                pa = 0;
                while(l<=r && pa<=pb){
                    pa += arr[l];
                    a += arr[l];
                    ++l;
                }
                ++moves;
                turn ^= 1;
            }
            else { // Bob
                pb = 0;
                while(l<=r && pa>=pb){
                    pb += arr[r];
                    b += arr[r];
                    --r;
                }
                ++moves;
                turn ^= 1;
            }
        }
        printf("%d %d %d\n", moves, a, b);
    }
}