#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int giamLeft[1000005];
int giamRight[1000005];
int tangLeft[1000005];
int tangRight[1000005];
int doi=0;
int TL=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    giamLeft[1]=0;
    giamRight[n]=0;
    tangLeft[1]=0;
    tangRight[n]=0;
    for (int i=2;i<=n;i++){
        if (a[i]>a[i-1]) {
            tangLeft[i]=tangLeft[i-1]+1;
        }
        else if (a[i]<a[i-1]){

            giamLeft[i]=giamLeft[i-1]+1;
        }

    }
    for (int i=n-1;i>=1;i--){
        if (a[i]>a[i+1]) {
            giamRight[i]=giamRight[i+1]+1;
        }
        else if (a[i]<a[i+1]){
            tangRight[i]=tangRight[i+1]+1;
        }

    }

    for (int i=1;i<=n;i++){

            doi=max(doi,min(tangLeft[i],giamRight[i]));


    }
    cout<<doi<<" ";

    for (int i=1;i<=n;i++){
            TL=max(TL,min(tangRight[i],giamLeft[i]));
    }
    cout<<TL;



}
