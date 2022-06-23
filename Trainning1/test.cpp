#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    int a[100000];
    int x;
    for (int i=1;i<=n;i++){
        cin>>x;
        a[x]=1;
    }
    int r=1;
    cin>>m;
    for (int i=1;i<=m;i++){
        cin>>x;
        if (a[x]==1) continue;
        else{
            r=0; break;
        }
    }
    cout<<r;

}
