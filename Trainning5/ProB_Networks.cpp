#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int m;

int a[10005][10005];
void input(){
    cin>>n>>k;
    cin>>m;
    int b,c,d;
    for (int i=1;i<=m;i++){
        cin>>b>>c>>d;
        a[b][c]=d;
        a[c][b]=d;
    }
    for (int i=1;i<=n;i++){
       for (int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
       }
       cout<<endl;
    }
}

int main(){
    input();
    return 0;
}
