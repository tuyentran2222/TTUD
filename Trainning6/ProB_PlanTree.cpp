#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int m=0;
bool compare(int a,int b){
    return a>b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,compare);
    for (int i=1;i<=n;i++){
        //cout<<a[i]<<" ";
        m=max(a[i]-(n-i),m);
    }
    //cout<<"m= "<<m<<endl;
    cout<< n+m+1;
    return 0;
}
