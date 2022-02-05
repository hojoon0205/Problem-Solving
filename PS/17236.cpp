#include<bits/stdc++.h>
using namespace std;

int main(){
    long double h1, h2, h3;
    cin >> h1 >> h2 >> h3;
    cout << fixed;
    cout.precision(10);
    cout << sqrt( 1 / ( (1.0/h1+1.0/h2+1.0/h3)*(-1.0/h1+1.0/h2+1.0/h3)*(1.0/h1-1.0/h2+1.0/h3)*(1.0/h1+1.0/h2-1.0/h3) ) ) << endl;
}