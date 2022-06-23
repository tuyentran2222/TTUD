#include <bits/stdc++.h>
using namespace std;
# define M_PI 3.14159265358979323846
int N,F;
int c;//tong so test case
int r[10005];
double dientich[10005];

bool Kiemtra(double m){
    int cFriend=0;
    if (m==0) return false;
    for (int i=1;i<=N;i++){
        cFriend+= (int)(dientich[i]/m);
    }
    if (cFriend>=F) return true;

    return false;
}

double resolve(){
    double l=0;
    double r=dientich[N];
    while (r-l>=0.000001){
        double m=(l+r)/2;
        if (Kiemtra(m)){
            l=m;
        }
        else r=m;
    }
    return l;
}

int main(){
    cin>>c;
    for (int i=0;i<c;i++){
        cin>>N>>F;
        F=F+1;
        for (int j=1;j<=N;j++){
            cin>>r[j];
            dientich[j]=M_PI*r[j]*r[j];

        }
        sort(dientich+1,dientich+N+1);
        double res=resolve();
        printf("%.6lf",res);
        cout<<endl;
    }

}
