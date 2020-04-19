#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    cout << (n/(a+b) * a) + ((n%(a+b))>=a?a:(n%(a+b))) << endl;
}