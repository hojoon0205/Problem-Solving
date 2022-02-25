#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(true){
        int N; cin >> N;
        if(N==0) break;
        cin.ignore();
        string str; getline(cin, str);
        //cout << str << endl;
        map<char,int> cnt;
        int ans = 0, l = 0, p = 0;
        for(char &x : str){
            ++cnt[x]; ++l;
            if(cnt.size() > N){
                while(p<str.length() && cnt.size() > N){
                    --cnt[str[p]]; --l;
                    if(cnt[str[p]]==0) cnt.erase(str[p]);
                    ++p;
                }
            }
            ans = max(ans, l);
        }
        cout << ans << "\n";
    }
}