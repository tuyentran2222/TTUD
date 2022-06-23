#include<bits/stdc++.h>
using namespace std;
int distance1[21][21];
int n,m;
int cmin=INT_MAX;
int minDistance=INT_MAX;
int curr;// chi phi hien tai
int x,y,c;
int b[21];//luu  giu cac thanh pho da di
int visited[21];
void TRY(int k){
        for(int i = 2; i <= n; i++){
            if (visited[i]==0&&distance1[b[k-1]][i]!=0){
                visited[i]=1;
                b[k]=i;
                curr=curr+distance1[b[k-1]][i];
                if (k==n){
                    if (distance1[b[k]][1]==0) {
                        curr=curr-distance1[b[k-1]][i];
                        visited[i]=0;
                        continue;
                    }
                    else if ((curr+distance1[b[k]][1])<minDistance ) minDistance=curr+distance1[b[k]][1];
                }
                else{
                    if (curr+(n-k+1)*cmin<minDistance) TRY(k+1);
                }
                curr=curr-distance1[b[k-1]][i];
                visited[i]=0;
            }
    }
}


int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            distance1[i][j]=0;
        }
    }
    visited[1]=1;
    b[1]=1;
    for (int i=2;i<=n;i++){
        visited[i]=0;
    }
    for (int i=1;i<=m;i++){
        cin>>x>>y>>c;
        distance1[x][y]=c;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (distance1[i][j]>0) cmin=min(cmin,distance1[i][j]);
        }
    }
    TRY(2);
    cout<<minDistance;

}
