#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
int CombinationGen(){
    int res=0;
    int j=0;
    int i;
    for (i=m-1;i>=0;i--){
        if (a[i]!=n-j){
            a[i]++;
            res=1;
            break;
        }

        j++;
    }
    for (j=i+1;j<m;j++){
        a[j]=a[j-1]+1;
    }
    return res;

}
int main(){
    cin>>n>>m;
    for (int i=0;i<m;i++){
        cin>>a[i];
    }
    int res=CombinationGen();
    if (res==0) cout<< "-1";
    else {
        for (int i=0;i<m;i++){
            cout<<a[i]<<" ";
        }
    }
}
