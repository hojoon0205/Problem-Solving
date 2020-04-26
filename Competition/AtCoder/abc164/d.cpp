#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cnt[2020], ans;

int main()
{
    string s;
    cin >> s;
    int l = s.length();
    int x = 0; ++cnt[x]; int t = 1;
    for(int i=l-1; i>=0; --i){
        x = (x+(t*(s[i]-'0')))%2019;
        ++cnt[x];
        t = (t*10)%2019;
    }
    for(int i=0; i<2019; ++i) ans += (cnt[i]*(cnt[i]-1))/2;
    cout << ans << endl;
}