#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s, rs;
    cin >> s;
    int n = s.length();
    int h = n/2;
    rs = s;
    reverse(rs.begin(), rs.end());

    if(s==rs && s.substr(0, h) == s.substr(h+1, h)) printf("Yes\n");
    else printf("No\n");
}