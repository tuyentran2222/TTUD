#include<bits/stdc++.h>
using namespace std;
int n;
int a[10005];
int lis[10005];//luu tru do dai chuoi tang ket thuc tai i
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        lis[i]=1;
        for (int j=1;j<=i-1;j++){
            if (a[j]<a[i]&&(lis[i]<lis[j]+1)) lis[i]=lis[j]+1;
        }
    }
    int cmax=0;
    for(int i=1;i<=n;i++){
        cmax=max(cmax,lis[i]);
    }

    cout<<cmax;
}
