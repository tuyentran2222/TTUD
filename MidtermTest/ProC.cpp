#include<bits/stdc++.h>
using namespace std;
int a[20005];
int n,M,m;
int tong1[20005];
int tong2[20005];
//int tong[20005][20005];
int k;
int dem=0;


void input(){
    cin>>n>>m>>M;
    tong1[0]=0;
    tong2[n+1]=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        tong1[i]=tong1[i-1]+a[i];
    }
    for (int i=n;i>=1;i--){
        tong2[i]=tong2[i+1]+a[i];
    }
}
int solve(){
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            //cout<<tong1[i]<< " "<<tong2[j]<<endl;
            k=tong1[n]-tong1[i-1]-tong2[j+1];
            if (k>=m&&k<=M) dem++;
        }
    }
}
int main(){
    input();
    solve();
    cout<<dem;
    return 0;
}
