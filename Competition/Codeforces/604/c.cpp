#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    if(n==1){ cout << 1 << endl; return 0; }
    int c = 0, cc = 0, ans = 0, ccc=0;
    char bef = '2';
    for(int i=0; i<n; ++i){
        if(bef != s[i]){
            if(c>1) ++cc;
            if(c>2) ++ccc;
            ++ans;
            c=1;
        }
        else ++c;
        bef = s[i];
    }
    if(c>1) ++cc;
    if(c>2) ++ccc;
    if(cc>=2 || ccc>0) printf("%d\n", ans+2);
    else if(cc==1) printf("%d\n", ans+1);
    else printf("%d\n", ans);
}