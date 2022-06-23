#include<bits/stdc++.h>
using namespace std;
int n,m;
int x[10005];
int y[10005];
int L[10005][10005];//luu tru do dai day con lon nhat ket thuc boi xi va yj

int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>x[i];
        L[i][0]=0;
    }
    for (int i=1;i<=m;i++){
        cin>>y[i];
        L[0][i]=0;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (x[i]==y[j]){
                L[i][j]=L[i-1][j-1]+1;
            }
            else L[i][j]=max(L[i-1][j],L[i][j-1]);
        }
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            cout<<L[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<L[n][m];

}
