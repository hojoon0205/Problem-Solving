#include<bits/stdc++.h>
using namespace std;
int main()
{
    int diff;
    const int M = 262143, a = 131071;
    scanf("%d", &diff);
    int b = M - diff;
    printf("2 3\n");
    printf("262143 131071 0\n");
    printf("%d 262143 131071\n", b);
}