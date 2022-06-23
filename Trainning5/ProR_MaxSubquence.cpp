#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
int L[1000005];
int main(){
    cin>>n;
    int cmax=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    L[0]=0;
    for (int i=1;i<=n;i++){
        L[i]=max(0,L[i-1]+a[i]);
        cmax=max(cmax,L[i]);
    }
    cout<<cmax;
}
