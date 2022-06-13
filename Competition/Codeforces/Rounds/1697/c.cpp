#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    for(;T--;){
        int N; cin >> N;
        string A, B; cin >> A >> B;
        int c[3] = {0,0,0};
        for(int i=0; i<N; ++i) ++c[A[i]-'a'], --c[B[i]-'a'];
        if(c[0] || c[1] || c[2]){
            cout << "NO\n"; continue;
        }
        string acA, acB;
        for(int i=0; i<N; ++i){
            if(A[i] != 'b') acA += A[i];
            if(B[i] != 'b') acB += B[i];
        }
        if(acA != acB){
            cout << "NO\n"; continue;
        }
        vector<int> bA, bB;
        for(int i=0; i<N; ++i){
            if(A[i]=='b') bA.push_back(i);
            if(B[i]=='b') bB.push_back(i);
        }
        bool ans = true;
        int la=-1, lc=N+1;
        for(int i=0; i<bA.size(); ++i){
            int pa = bA[i], pb = bB[i];
            if(pa==pb) continue;
            if(pa > pb){
                //a
                for(int j=max(la,pb); j<pa; ++j) if(A[j]!='a') { ans=false; break; }
                if(!ans) break;
                la = pa;
                swap(A[pa], A[pb]);
                bA[i] = pb;
            }
        }
        for(int i=bA.size()-1; i>=0; --i){
            int pa = bA[i], pb = bB[i];
            if(pa==pb) continue;
            if(pa < pb){
                //c
                for(int j=min(lc,pb); j>pa; --j) if(A[j]!='c') { ans=false; break; }
                if(!ans) break;
                lc = pa;
                swap(A[pa], A[pb]);
            }
        }
        cout << (ans?"YES\n":"NO\n");
    }
}