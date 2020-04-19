#include<bits/stdc++.h>
using namespace std;
#define ll long long

char filenum, input_filename[50], output_filename[50];
ll hashf(char* tag){
    ll ret = 0;
    while(*tag){
        ret = ret*37;
        if(*tag >= 'a' && *tag <= 'z') ret += *tag - 'a' + 1;
        else ret += *tag - '0' + 27;
        ++tag;
    }
    return ret;
}
map<ll, int> tag_id;

struct Pic{
    bool type;// true:H, false:V
    int tagnum;
    vector<int> tagids;
    int idx;

    //bool used = false;
};

Pic arr[99999];

int n, tagcnt;

set<int> unused;

int main()
{
    int i, j;
    filenum = 'c';
    sprintf(input_filename, "qualification_round_2019.in/%c-merge.txt", filenum);
    sprintf(output_filename, "%c.txt", filenum);
    freopen(input_filename, "r", stdin);
    //freopen(output_filename, "w", stdout);
    FILE *fout = fopen(output_filename, "w");

    scanf("%d", &n);
    char type, tag[20]; int tagnum;
    for(int i=1; i<=n; ++i){
        scanf("\n%c %d", &type, &tagnum);
        arr[i].type = (type=='H');
        arr[i].tagnum = tagnum;
        arr[i].idx = i-1;
        for(int j=1; j<=tagnum; ++j){
            scanf(" %s", tag);
            ll taghash = hashf(tag);
            if(tag_id.find(taghash) == tag_id.end())
                tag_id[taghash] = ++tagcnt;
            int tagid = tag_id[taghash];
            arr[i].tagids.push_back(tagid);
        }
        sort(arr[i].tagids.begin(), arr[i].tagids.end());
        if(i>1) unused.insert(i);
    }
    
    fprintf(fout, "%d\n0\n", n);
    int prev=0;
    for(int i=2; i<=n; ++i){
        int p; int maxscore=0;
        vector<int> inter;
        for(auto j : unused){
            inter.clear();
            set_intersection(arr[prev].tagids.begin(), arr[prev].tagids.end(),
                             arr[j].tagids.begin(), arr[j].tagids.end(),
                             back_inserter(inter));
            if(maxscore <= inter.size()){ p = j; maxscore = inter.size(); }
        }
        unused.erase(p);//arr[p].used = true;
        if(i%100 == 0) printf("%d %d\n", i, maxscore);
        fprintf(fout, "%d\n", p-1);
        prev = p;
    }
}