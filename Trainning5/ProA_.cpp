#include<bits/stdc++.h>
using namespace std;
int n,L1,L2;
long long L[100005];
long long a[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>L1>>L2;
    for (int i=1;i<=n;i++){
        cin>> a[i];
        L[i]=0;
    }

    for (int i=1;i<=L1;i++){
        L[i]=a[i];
    }
    L[L1+1]=L[1]+a[L1+1];
    for (int i=L1+2;i<=n;i++){
        for (int j=i-L2;j<=i-L1;j++){
            L[i]=max(L[i],L[j]+a[i]);
        }
    }
    long long kq=0;
    for (int i=1;i<=n;i++){
        kq=max(kq,L[i]);
        cout<<L[i]<<" ";
    }
    cout<<kq;
}
