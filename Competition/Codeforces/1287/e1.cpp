#include<bits/stdc++.h>
using namespace std;
int n;
map<string, int> strs;
vector<string> subs;
char ans[110];
int main()
{
    cin >> n;
    cout << "? 1 " << n << endl; cout.flush();
    for(int i=1; i<=n*(n+1)/2; ++i){
        string tmp;
        
        cin >> tmp;
        if(strs.find(tmp) == strs.end()) strs[tmp] = 1;
        else ++strs[tmp];
    }
    // for(auto x : strs){
    //     cout << x.first << " " << x.second << endl;
    // }
    
    cout << "? 2 " << n << endl; cout.flush();
    for(int i=1; i<=n*(n-1)/2; ++i){
        string tmp;
        cin >> tmp;
        if(strs[tmp] == 1) strs.erase(tmp);
        else --strs[tmp];
    }
    // for(auto x : strs){
    //     cout << x.first << " " << x.second << endl;
    // }

    for(auto x : strs)
        subs.push_back(x.first);
    sort(subs.begin(), subs.end(), [](string &a, string &b)->bool{return a.length()<b.length();});
    ans[0] = subs[0][0];
    for(int i=1; i<subs.size(); ++i){
        int cnt[26];
        for(int j=0; j<26; ++j) cnt[j] = 0;
        for(int j=0; j<subs[i].length(); ++j) ++cnt[subs[i][j]-'a'];
        for(int j=0; j<subs[i-1].length(); ++j) --cnt[subs[i-1][j]-'a'];
        for(int j=0; j<26; ++j){
            if(cnt[j]) ans[i] = j+'a';
        }
    }
    cout << "! " << ans << endl; cout.flush();
}