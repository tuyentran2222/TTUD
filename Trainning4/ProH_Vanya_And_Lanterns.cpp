#include<bits/stdc++.h>
using namespace std;
int n;//the number of lanterns
int l;//the length of the street
int a[1005];
double cmin=0;
int main(){
    cin>>n>>l;
    for (int i=1;i<=n;i++){
        a[i]=-1;
    }
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    for (int i=2;i<=n-1;i++){
        cmin=max(cmin,(double)(a[i]-a[i-1]));
    }
    cmin=cmin/2;
    if (a[1]==0) cmin=max(cmin,(double)a[2]/2);
    else cmin=max(cmin,(double)a[1]);
    //cout<<"amin="<<cmin<<endl;
    if (a[n]==l) cmin=max(cmin,(double)(a[n]-a[n-1])/2);
    else cmin=max(cmin,(double)(l-a[n]));
    //cout<<"amin="<<cmin<<endl;
    printf("%.9lf",cmin);
}

