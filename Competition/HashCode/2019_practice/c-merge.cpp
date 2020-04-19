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
    vector<string> tags;
    int idx;

    //bool used = false;
};

set<int> unused;
Pic arr[99999];

int n;

int main()
{
    int i, j;
    filenum = 'c';
    sprintf(input_filename, "qualification_round_2019.in/%c.txt", filenum);
    sprintf(output_filename, "qualification_round_2019.in/%c-merge.txt", filenum);
    ofstream fout;
    ifstream fin;
    fin.open(input_filename);
    fout.open(output_filename);

    fin >> n;
    char type; int tagnum;
    for(i=1; i<=n; ++i){
        fin >> type >> tagnum;
        arr[i].type = (type=='H');
        
    }
}