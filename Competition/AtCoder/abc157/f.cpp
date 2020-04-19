#include<bits/stdc++.h>
using namespace std;

int N, K;
double xyc[70][3];

bool isoverk(double X, double Y, double Time){
    int cnt = 0;
    for(int i=1; i<=N; ++i){
        double x = X - xyc[i][0], y = Y - xyc[i][1], c = xyc[i][2];
        if(c * sqrt(x*x + y*y) <= Time) ++cnt;
        if(cnt>=K) return true;
    }
    return false;
}

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    int i, j;
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; ++i){
        scanf("%lf%lf%lf", &xyc[i][0], &xyc[i][1], &xyc[i][2]);
    }
    double L = 0.0, R = 300000.0, T_;
    while(R-L >= 0.000001f){
        T_ = (L+R)/2.0;
        bool chk = false;
        for(int i=1; i<N; ++i){
            for(int j=i+1; j<=N; ++j){
                if(dist(xyc[i][0], xyc[i][1], xyc[j][0], xyc[j][1]) < (T_/xyc[i][2] + T_/xyc[i][2]))
                    continue;
                
                //
            }
        }
    }
}