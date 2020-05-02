#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    scanf("%d%d", &n, &m);
    vector<pair<int,int>> diffs;
    for(int i=1; i<=m; ++i) diffs.push_back(make_pair(i, n-i));
    vector<int> difs;
    for(auto x : diffs) difs.push_back(x.first&1?x.second:x.first);
    sort(difs.begin(), difs.end());
    for(int i=1; i<=m; ++i){
        printf("%d %d\n", i, i+difs[m-i]);
    }
}