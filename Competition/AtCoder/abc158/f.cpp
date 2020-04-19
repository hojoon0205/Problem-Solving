#include<bits/stdc++.h>
using namespace std;

#define MOD 998244353
#define ll long long

int n;

struct A{
    int X, D;
    int r_idx;
    ll f;
};

int tree[800010], S;
void update(int i, int v){
    i += S; tree[i] = v; i/=2;
    while(i){
        tree[i] = max(tree[i*2], tree[i*2+1]);
        i/=2;
    }
}
int get_max(int l, int r){
    l += S; r += S;
    int ret = 0;
    while(l<r){
        if(l%2 == 1){ ret = max(ret, tree[l]); ++l; }
        if(r%2 == 0){ ret = max(ret, tree[r]); --r; }
        l/=2; r/=2;
    }
    if(l==r) ret = max(ret, tree[l]);
    return ret;
}

int main()
{
    scanf("%d", &n);
    for(S=1;S<n;S<<=1);
    vector<A> arr(n);
    for(int i=0; i<n; ++i){
        scanf("%d%d", &arr[i].X, &arr[i].D);
    }
    sort(arr.begin(), arr.end(), [](A &a, A &b)->bool{
        return a.X < b.X;
    });
    A tmp; tmp.f = 1; tmp.X = 1111111111; tmp.D = 1000000000; tmp.r_idx = n;
    arr.push_back(tmp);
    vector<int> Xs;
    for(auto t : arr){
        Xs.push_back(t.X);
    }
    arr[n-1].r_idx = n-1; update(n-1, n-1);
    for(int i=n-2; i>=0; --i){
        int key = arr[i].X + arr[i].D;
        int idx = lower_bound(Xs.begin(), Xs.end(), key) - Xs.begin();
        if(idx <= i+1) arr[i].r_idx = i;
        else arr[i].r_idx = get_max(i+1, idx-1);
        update(i, arr[i].r_idx);
    }
    //for(int i=S; i<=S+n-1; ++i) printf("%d ", tree[i]);
    //printf("\n\n");
    //for(int i=0; i<=n; ++i) printf("%10d %10d %d %lld\n", arr[i].X, arr[i].D, arr[i].r_idx, arr[i].f);
    for(int i=n-1; i>=0; --i){
        arr[i].f = (arr[i+1].f + arr[arr[i].r_idx+1].f) % MOD;
    }
    printf("%lld\n", arr[0].f);
}