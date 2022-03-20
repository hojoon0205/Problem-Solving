#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


using ll = long long;

ll cnt[20]={
    0,
    9,
    15,
    309,
    3675,
    43462,
    486887,
    5311174,
    57110375,
    607393752,
    6387527554,
    66540506560,
    688142674977,
};
ll scnt[20]={0,9,24,333,4008,47470,534357,5845531,62955906,670349658,7057877212,73598383772,761741058749};
ll zcnt[20]={0,0,9,171,2439,30951,368559,4217031,46953279,512579511,5513215599,58618940391,617570463519};
ll fact[13] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};
ll pows[20][20];

ll dcnt[10], premul=1, presum;

void _back(int cur, ll su, int X,  ll &ans){
    if(cur==1){
        if(su!=X*cur) return;
        dcnt[cur] = X?su/cur:0;
        ll c = premul;
        for(int i=1; i<=9; ++i) c *= pows[i][ dcnt[i] ];
        ll isu = presum;
        for(int i=1; i<=9; ++i) isu += i*dcnt[i];
        if(c%isu){ dcnt[cur] = 0; return; }
        ll s=0;
        for(int i=1; i<=9; ++i) s+=dcnt[i];
        s = fact[s];
        for(int i=1; i<=9; ++i) s /= fact[dcnt[i]];
        ans += s;
        dcnt[cur] = 0;
        return;
    }
    for(int i=0; i<=X; ++i){
        if(su < i*cur) return;
        dcnt[cur] += i;
        _back(cur-1, su - i*cur, X-i, ans);
        dcnt[cur] = 0;
    }
}

void back(ll N, ll &ans){
    for(ll s=N; s<=9*N; ++s){
        ll tmp = s+presum;
        for(ll x : {2,3,5,7}) while(tmp%x==0) tmp/=x;
        if(tmp!=1) continue;
        _back(9, s, N, ans);
    }
}

// [1,X]
ll f(ll X){
    memset(dcnt, 0, sizeof(dcnt));
    premul = 1; presum = 0;
    if(X<=10) return X;/*
    if(X<=100000){
        ll ret = 0;
        for(ll i=1; i<=X; ++i){
            ll t = i, mu = 1, su = 0;
            while(t){ mu *= (t%10); su += (t%10); t/=10; }
            if(mu%su==0) ++ret;
        }
        return ret;
    }*/
    ll ANS = 0;
    ll p10, cn=0;
    for(p10=1;p10<=X;p10*=10,++cn) ANS += cnt[cn];
    p10/=10;--cn;

    //cout << p10 << " " << cn << " " << ANS << endl;

    ll T = X; bool fir = true;
    while(p10){
        ll D = T/p10;
        if(D==0){
            ANS += T+1;
            return ANS;
        }
        if(!fir) ANS += p10;
        for(int i=1; i<D; ++i){
            ANS += zcnt[cn+1]/9;
            premul *= i;
            presum += i;
            back(cn, ANS);
            premul /= i;
            presum -= i;
        }
        premul *= D;
        presum += D;
        T %= p10;
        p10/=10; --cn;
        fir = false;
    }
    if(premul % presum == 0) ++ANS;

    return ANS;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(ll i=1; i<=9; ++i){
        pows[i][0] = 1;
        for(ll j=1; j<=12; ++j) pows[i][j] = pows[i][j-1]*i;
    }

    int T; cin >> T;
    for(int tt=1; tt<=T; ++tt){
        cout << "Case #" << tt << ": ";
        ll A, B; cin >> A >> B;
        cout << f(B) - (A==1?0:f(A-1));
        cout << "\n";
    }
}