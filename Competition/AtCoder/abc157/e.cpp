#include<bits/stdc++.h>
using namespace std;

int n, q, b;
char str[600000];
int bucket[2000][26];

int get_q(int l, int r){
    int cnt[26], c=0;
    for(int i=0; i<26; ++i) cnt[i] = 0;
    if(l/b == r/b){
        for(int i=l; i<=r; ++i) cnt[str[i]-'a']++;
        for(int i=0; i<26; ++i) c += cnt[i]?1:0;
        return c;
    }
    int lb = (l+b-1)/b;
    int rb = (r<b-1)?-1:((r-b+1)/b);
    //printf("\n\n%d %d\n\n", lb, rb);
    for(int i=lb; i<=rb; ++i){
        for(int j=0; j<26; ++j) cnt[j] += bucket[i][j];
    }
    for(int i=l; i<lb*b && i<=r; ++i) cnt[str[i]-'a']++;
    for(int i=(rb+1)*b; i<=r; ++i) cnt[str[i]-'a']++;
    for(int i=0; i<26; ++i) c += cnt[i]?1:0;
    return c;
}

int main()
{
    int i, j;
    scanf("%d\n%s\n%d", &n, str, &q);
    for(b=1;b*b<n;++b);
    for(int i=0; i<n; ++i){
        ++bucket[i/b][str[i]-'a'];
    }
    for(;q--;){
        int t; scanf("\n%d", &t);
        if(t==1){
            int x; char y;
            scanf(" %d %c", &x, &y); --x;
            --bucket[x/b][str[x]-'a'];
            str[x] = y;
            ++bucket[x/b][str[x]-'a'];
        }
        else{
            int x, y;
            scanf(" %d %d", &x, &y);
            printf("%d\n", get_q(x-1, y-1));
        }
    }
}