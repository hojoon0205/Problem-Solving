#include<bits/stdc++.h>
using namespace std;
int n, m;
char str[100010];
int arr[100010];
int main()
{
    scanf("%d", &n);
    for(;n--;){
        int ans = 0;
        scanf("%d", &m);
        scanf("%s", str);
        for(int i=1; i<m; ++i){
            if(str[i-1]=='A' && str[i]=='P')
                arr[i] = 1;
            else if(str[i]=='P' && arr[i-1]>0)
                arr[i] = arr[i-1]+1;
            else
                arr[i] = 0;
            
            ans = max(ans, arr[i]);
        }
        printf("%d\n", ans);
    }
}