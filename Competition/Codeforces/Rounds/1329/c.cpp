#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int h, g;

struct Node{
    int val;
    int l;
    int r;
    bool can_called;
    int remain;
}heap[3000000];

vector<int> ans;
ll s;

void f(int no);
void func(int node);

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        scanf("%d%d", &h, &g);
        s=0;
        for(int i=1; i<(1<<h); ++i){
            scanf("%d", &heap[i].val);
            s += (ll)heap[i].val;
            heap[i].l = i*2;
            heap[i].r = i*2+1;
            heap[i].can_called = true;
        }
        ans.clear();
        for(int i=(1<<h); i<(1<<(h+1)); ++i){ heap[i].val = heap[i].remain = 0; heap[i].can_called = false; }
        for(int i=(1<<h)-1; i>=1; --i) heap[i].remain = heap[heap[i].l].remain + heap[heap[i].r].remain + ((i<(1<<g))?0:1);
        for(int i=(1<<g); i<(1<<h); ++i){
            // printf("\n%dth step\n", i-(1<<g)+1);
            func(1);
            // printf("\n");
            // for(int i=1; i<(1<<h); ++i) printf("%d ", heap[i].remain);
        }
        printf("%lld\n", s);
        for(auto x : ans) printf("%d ", x);
        printf("\n");
    }
}

void f(int no){
    // printf("f%d ", no);
    int node = no;
    while(heap[node*2].val | heap[node*2+1].val){
        node = heap[node*2].val > heap[node*2+1].val ? node*2 : node*2+1;
    }
    int L = heap[node].l, R = heap[node].r;
    
    if(node >= (1<<g)){
        s -= (ll)heap[no].val;
        ans.push_back(no);
        while(heap[no*2].val | heap[no*2+1].val){
            if(heap[no*2].val > heap[no*2+1].val){ heap[no].val = heap[no*2].val; no = no*2; }
            else{ heap[no].val = heap[no*2+1].val; no = no*2+1; }
        }
        heap[node].val = 0;
        for(int i=node; i>=1; i/=2) heap[i].remain -= 1;
        return;
    }
    for(int i=node; i>=1; i/=2) heap[i].can_called = false;
    func(node^1);
    return;
}

void func(int node){
    // printf("%d ", node);
    if(heap[node].can_called){
        f(node);
        return;
    }
    int L = heap[node].l, R = heap[node].r;
    if(heap[L].remain>0) func(L);
    else func(R);
    return;
}