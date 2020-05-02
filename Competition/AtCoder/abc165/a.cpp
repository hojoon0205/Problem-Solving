#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k, a, b;
    scanf("%d%d%d", &k, &a, &b);
    printf("%s\n", ((b/k)==((a-1)/k))?"NG":"OK");
}