#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000000

int main()
{
    srand(time(NULL));
    printf("300000\n");
    for(int i=1; i<=300000; ++i) printf("%d ", rand()%MOD + 1);
    printf("\n300000\n");
    for(int i=1; i<=300000; ++i) printf("%d %d\n", rand()%300000 + 1, rand()%MOD + 1);
    return 0;
}