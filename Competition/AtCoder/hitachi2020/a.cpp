#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    if(S.length() % 2){ printf("No\n"); return 0; }
    string X = "";
    for(int i=1; i<=(S.length() / 2); ++i) X += "hi";
    if(X == S){ printf("Yes\n"); }
    else printf("No\n");
}