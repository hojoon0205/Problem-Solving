#include<bits/stdc++.h>
using namespace std;

int cnt[100010];

int main()
{
    int x, y, z;
    int N;
    scanf("%d", &N);
    for(x=1; x<=100; ++x){
        for(y=1; y<=100; ++y){
            for(z=1; z<=100; ++z){
                ++cnt[x*x+y*y+z*z+x*y+y*z+z*x];
            }
        }
    }
    for(int i=1; i<=N; ++i) printf("%d\n", cnt[i]);
}