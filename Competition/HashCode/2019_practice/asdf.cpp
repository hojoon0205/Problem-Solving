#include<bits/stdc++.h>
using namespace std;

char filenum, input_filename[50], output_filename[50];

int main()
{
    int i, j;
    scanf("%c", &filenum);
    sprintf(input_filename, "qualification_round_2019.in/%c.txt", filenum);
    sprintf(output_filename, "%c.txt", filenum);
    freopen(input_filename, "r", stdin);
    freopen(output_filename, "w", stdout);

    
}