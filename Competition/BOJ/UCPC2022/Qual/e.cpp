#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = double;
int N;
const ld D = 31536000;

ll get_second(string &S1, string &S2){
    ll year = stoi(S1.substr(0,4));
    ll month = stoi(S1.substr(5,2));
    ll day = stoi(S1.substr(8,2));
    ll hour = stoi(S2.substr(0,2));
    ll min = stoi(S2.substr(3,2));
    ll sec = stoi(S2.substr(6,2));
    int md[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    //cout << year << " " << month << " " << day << endl;
    day += 365*(year-2019);
    day += md[month-1];
    if(year>2020 || (year==2020 && month>=3)) day+=1;
    //cout << day << endl;
    return day*86400 + hour*3600 + min*60 + sec;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    if(N==0){ cout << "0\n"; return 0; }
    vector<pair<ld,ld>> V(N);
    for(int i=0; i<N; ++i){
        string s1, s2; ll x;
        cin >> s1 >> s2 >> x;
        ll t = get_second(s1,s2);
        V[i] = {t, x};
    }
    vector<ld> p(N);
    for(int i=0; i<N; ++i) p[i] = max( pow(0.5, (V[N-1].first - V[i].first)/D), 
                                       pow(0.9, (double)(N-1-i)) );
    ld a=0, b=0;
    for(int i=0; i<N; ++i){
        a += p[i]*V[i].second;
        b += p[i];
    }
    cout << (int)(a/b + 0.5) << endl;
}