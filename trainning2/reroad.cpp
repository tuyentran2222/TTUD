#include<bits/stdc++.h>
using namespace std;
int dgg;
int t[100004];
int q,p,c;
int n;
int d(int i){
    if (i==1){
        return 1;
    }
    else if (t[i]==t[i-1]){
        return 0;
    }
    else return 1;
}
int query(int p,int c){
    dgg -= d(p);
    if (p<n) dgg -= d(p+1);
    t[p]=c;
    dgg+=d(p);
    if (p<n) dgg+=d(p+1);
}
int main(){

    cin>>n;
    dgg=0;
    for (int i=1;i<=n;i++){
        cin>>t[i];
    }

    cin>>q;
    for (int i=1;i<=n;i++){
        dgg+=d(i);
    }
    for (int i=1;i<=q;i++){
        cin>>p>>c;
        cout<<query(p,c)<<endl;
    }
}
