#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<int> last(26,0);
    cout << "? 1 1" << endl;
    string ans(N, '*');
    cin >> ans[0]; last[ans[0]-'a'] = 1;
    int kind = 1;
    for(int i=1; i<N; ++i){
        vector<pair<int,int>> v;
        for(int x=0; x<26; ++x) v.push_back({last[x], x});
        sort(v.begin(), v.end());
        cout << "? 2 1 " << i+1 << endl;
        int t; cin >> t;
        if(kind < t){
            ++kind;
            cout << "? 1 " << i+1 << endl;
            cin >> ans[i];
            last[ans[i]-'a'] = i+1;
            continue;
        }
        else if(kind == 1){
            ans[i] = ans[0];
            last[ans[i]-'a'] = i+1;
            continue;
        }
        int l=26-kind, r=24, ansl = 26-kind;
        while(l<=r){
            int m = (l+r)/2;
            cout << "? 2 " << (v[m].first+1) << " " << i+1 << endl;
            int k; cin >> k;
            if(k == 26 - m) r = m-1;
            else{
                ansl = m+1;
                l = m+1;
            }
        }
        ans[i] = v[ansl].second + 'a';
        last[ans[i]-'a'] = i+1;
    }
    cout << "! " << ans << endl;
}