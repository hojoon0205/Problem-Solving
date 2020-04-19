#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    vector<int> A;
    cin >> K >> N;
    for(int i=0; i<N; ++i){
        int x;
        cin >> x;
        A.push_back(x);
    }
    int ans = 0;
    for(int i=1; i<N; ++i){
        ans = max(ans, A[i]-A[i-1]);
    }
    ans = max(ans, A[0]-A[N-1]+K);
    cout << K-ans << endl;
}