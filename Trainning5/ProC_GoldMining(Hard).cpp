#include<bits/stdc++.h>
using namespace std;
long long n,L1,L2;
long long L[1000005];
long long a[1000005];
long long cmax[1000005];//gia tri lon nhat cua L[i] ket thuc tai i
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>L1>>L2;
    for (int i=1;i<=n;i++){
        cin>> a[i];
    }
    //khoi tao mot so gia tri dau
    for (int i=1;i<=L1;i++){
        L[i]=a[i];
        cmax[i]=L[i];
    }
    L[L1+1]=L[1]+a[L1+1];
    //Khoi tao cmax dau
    for (int i=L1;i<=L2-L1+1;i++){
        cmax[L2]=max(L[i],cmax[L2]);
    }

    for (int i=L1+1;i<=n;i++){
        //j bien trung gian chi vi tri dau cua bai toan con truoc
        int j=i-L2;
        if (j<=0) j=1;

        L[i]=cmax[i-L1]+a[i];
        //Kiem tra gia tri lon nhat tren doan L2-L1+1 truoc co bang dau doan nay ko
        if (cmax[i-L1]!=L[j]){
            cmax[i-L1+1]=max(cmax[i-L1],L[i-L1+1]);
        }
        else{
            if (i-L2<=0){
                for (;j<=i-L1+1;j++){
                cmax[i-L1+1]=max(cmax[i-L1+1],L[j]);
                }
            }
            else{
                for (j=j+1;j<=i-L1+1;j++){
                cmax[i-L1+1]=max(cmax[i-L1+1],L[j]);
                }
            }

        }

    }
    long long kq=0;

    for (int i=1;i<=n;i++){
        kq=max(kq,L[i]);
    }
    cout<<kq;
}
