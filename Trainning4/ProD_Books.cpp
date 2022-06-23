#include<bits/stdc++.h>
using namespace std;
int N;
int m,k;
int a[505];
int tong[505];
int dd[505];
int t=0;

bool test(int mid){
    int c=0;
    int tong=0;
    for (int i=1;i<=m;i++){
        tong=tong+a[i];
        if (tong<mid){
            continue;
        }
        else if (tong>=mid) {
            tong=a[i];
            c++;
        }
    }
    if (c>=k) return true;
    else return false;
}
int solve(int l,int r){
    int mid;
    while(l<r){
        mid=(l+r)/2;
        //cout<<l<<" "<<mid<<" "<<r<<endl;
        if (test(mid)){
            if (l==r-1) return mid;
            l=mid;
        }
        else {
            if (l==r-1) return mid;
            r=mid;
        }

    }
    return mid;
}
int main(){
    cin>>N;

    for (int k1=1;k1<=N;k1++){
        t=0;
        cin>>m>>k;
        for (int j=1;j<=m;j++){
            cin>>a[j];
            dd[j]=0;
            t=t+a[j];
        }
        int res=solve(t/k,t);
        //cout<<res<<endl;
        int tt=0;
        int dem=0;
        for (int j=m;j>=1;j--){
            if (tt+a[j]<=res) {
                tt=tt+a[j];
                if (k-dem==j){
                    for (int i=1;i<=j-1;i++){
                        dd[i]=1;
                    }
                    break;
                }
                continue;
            }
            else {
                //cout<<"j="<<j<<endl;
                dem++;
                if (k-dem==j){
                    for (int i=1;i<=j;i++){
                        dd[i]=1;
                    }
                    break;
                }else{
                    dd[j]=1;
                    tt=a[j];
                }

            }
        }


        for (int j=1;j<=m;j++){
            cout<<a[j]<<" ";
            if (dd[j]==1) cout<<"/ ";
        }

        cout<<endl;
    }

}
