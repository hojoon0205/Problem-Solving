#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int n;
int arr[300010];
int dp[300010];
stack<int> in, de;
vector<int> idx;

struct SegTree{
    typedef int T; // Change this if you need
    T id = 9999999; // identity element (sum:0, mul:1, ...etc)
    T initval = 9999999;

    int S;
    vector<T> tree;
    T combine(T a, T b){
        // Real value, parent <- combine(child1, child2)
        return min(a,b);
    }

    SegTree(int N){
        for(S=1;S<N;S<<=1);
        tree.resize(S*2, initval);
    }
    void set_value(int i, T val){ set_value(i, val, 1, 1, S); }
    void set_value(int i, T val, int idx, int nl, int nr){
        if(i<nl || nr<i) return;
        if(nl==i && nr==i){
            tree[idx] = val;
            return;
        }
        int mid = (nl + nr) / 2;
        set_value(i, val, idx*2, nl, mid);
        set_value(i, val, idx*2+1, mid+1, nr);
        tree[idx] = combine(tree[idx*2], tree[idx*2+1]);
    }
    T query(int l, int r){ return query(l, r, 1, 1, S); }
    T query(int l, int r, int idx, int nl, int nr){
        if(r<nl || nr<l) return id;
        if(l<=nl && nr<=r) return tree[idx];
        int mid = (nl + nr) / 2;
        return combine( query(l, r, idx*2, nl, mid) , query(l, r, idx*2+1, mid+1, nr) );
    }
    T get_most_left(int l){ return get_most_left(l, S, 1, 1, S); }
    T get_most_left(int l, int r, int idx, int nl, int nr){
        if(r<nl || nr<l) return id;
        if(nl==nr) return tree[idx];
        if(l<=nl && nr<=r){
            if(tree[idx]==id) return id;
            int mid = (nl + nr) / 2;
            int _l = get_most_left(l, r, idx*2, nl, mid);
            return _l==id?get_most_left(l, r, idx*2+1, mid+1, nr):_l;
        }
        int mid = (nl + nr) / 2;
        int _l = get_most_left(l, r, idx*2, nl, mid);
        return _l==id?get_most_left(l, r, idx*2+1, mid+1, nr):_l;
    }
    T get_most_right(int r){ return get_most_right(1, r, 1, 1, S); }
    T get_most_right(int l, int r, int idx, int nl, int nr){
        if(r<nl || nr<l) return id;
        if(nl==nr) return tree[idx];
        if(l<=nl && nr<=r){
            if(tree[idx]==id) return id;
            int mid = (nl + nr) / 2;
            int _r = get_most_right(l, r, idx*2+1, mid+1, nr);
            return _r==id?get_most_right(l, r, idx*2, nl, mid):_r;
        }
        int mid = (nl + nr) / 2;
        int _r = get_most_right(l, r, idx*2+1, mid+1, nr);
        return _r==id?get_most_right(l, r, idx*2, nl, mid):_r;
    }
};

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &arr[i]);
    for(int i=1; i<=n; ++i) idx.push_back(arr[i]);
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());
    int M = idx.size();
    SegTree incST(M), decST(M);
    for(int i=1; i<=n; ++i) arr[i] = lower_bound(idx.begin(), idx.end(), arr[i]) - idx.begin() + 1;
    dp[1] = 0;
    in.push(1); incST.set_value(arr[1], 0);
    de.push(1); decST.set_value(arr[1], 0);
    for(int i=2; i<=n; ++i){
        dp[i] = dp[i-1] + 1;
        //printf("dp[i]:%d\n", dp[i]);
        if(arr[i] > arr[i-1]){
            int tmp = decST.query(arr[i-1], arr[i]-1);
            if(dp[i] > tmp+1) dp[i] = tmp+1;
            //printf("i:%d tmp:%d\n", i, tmp);
            tmp = decST.get_most_left(arr[i]);
            if(dp[i] > tmp+1) dp[i] = tmp+1;
            //printf("i:%d tmp:%d\n", i, tmp);
        }
        else if(arr[i] < arr[i-1]){
            int tmp = incST.query(arr[i]+1, arr[i-1]);
            if(dp[i] > tmp+1) dp[i] = tmp+1;
            //printf("i:%d tmp:%d\n", i, tmp);
            tmp = incST.get_most_right(arr[i]);
            if(dp[i] > tmp+1) dp[i] = tmp+1;
            //printf("i:%d tmp:%d\n", i, tmp);
        }
        //printf("dp[i]:%d\n", dp[i]);
        
        while(!in.empty() && arr[in.top()] >= arr[i]){
            incST.set_value(arr[in.top()], 9999999);
            in.pop();
        }
        in.push(i); incST.set_value(arr[i], dp[i]);
        while(!de.empty() && arr[de.top()] <= arr[i]){
            decST.set_value(arr[de.top()], 9999999);
            de.pop();
        }
        de.push(i); decST.set_value(arr[i], dp[i]);
    }
    printf("%d\n", dp[n]);
}