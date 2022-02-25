#include<bits/stdc++.h>
using namespace std;

int T, n, k, ans;

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &k);
        ans = (k/(n-1))*n + (k%(n-1));
        if(k%(n-1)==0) --ans;
        printf("%d\n", ans);
    }
}