#include<bits/stdc++.h>
using namespace std;

bool chk[10010];
vector<int> ans;

int main()
{
    int N;
    //scanf("%d", &N);
    N = 1024;
    ans.push_back(0);
    while(true){
        for(int i=1; i<N; ++i){
            for(int j=i+1; j<N; ++j){
                for(int k=j+1; k<N; ++k){
                    if(chk[i] || chk[j] || chk[k]) continue;
                    if(i^j^k) continue;
                    chk[i] = chk[j] = chk[k] = true;
                    ans.push_back(i);
                    ans.push_back(j);
                    ans.push_back(k);
                }
            }
        }
        int p;
        for(p=1; p<N; ++p){
            if(!chk[p]) break;
        }
        if(p>=N) break;
    }

    FILE *fout = fopen("input.txt","w");
    FILE *fout2 = fopen("realans.txt","w");
    fprintf(fout, "%d\n", N-1);
    for(int i=1; i<N; ++i) fprintf(fout, "%d\n", i);
    fclose(fout);
    for(int i=1; i<N; ++i) fprintf(fout2, "%d\n", ans[i]);
    fclose(fout2);

    system("./a.out < input.txt > output.txt");
    FILE *fin = fopen("output.txt","r");
    for(int i=1; i<N; ++i){
        int x;
        fscanf(fin, "%d\n", &x);
        if(ans[i] != x){
            printf("Error! %dth index\nYour output: %d\nAnswer: %d\n", i, x, ans[i]);
            break;
        }
    }
    fclose(fin);
}