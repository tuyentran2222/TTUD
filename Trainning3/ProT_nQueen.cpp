#include <bits/stdc++.h>
using namespace std;
#define MAX_N 12
int N,M;
int visited[MAX_N+1][MAX_N+1];
int dem=0;
bool check(int v,int k){
    int i,j;
    if (visited[v][k]==1) return false;
    //hang ngang
    for (i=k;i>=1;i--){
        if (visited[v][i]==2) return false;
    }
    for (i=v,j=k;i>=1,j>=1;i--,j--){
        if (visited[i][j]==2) return false;
    }
    for (i=v,j=k;i<=N,j>=1;i++,j--){
        if (visited[i][j]==2) return false;
    }
    return true;
}
int TRY(int k){
    for (int v=1;v<=N;v++){
        //cout<<"(v,k)=" <<v<<" "<< k<<" "<<check(v,k)<<endl;
        if (check(v,k)){
            visited[v][k]=2;
            if (k==N) dem++;
            else TRY(k+1);
            visited[v][k]=0;
        }
    }
}
int  main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool kt=false;

    while (!kt){
        dem=0;
        cin>>N>>M;
        for (int i=1;i<=N;i++){
            for (int j=1;j<=N;j++){
                visited[i][j]=0;
            }
        }
        if (N==0&&M==0) {
            kt=true;
            break;
        }
        for (int i=1;i<=M;i++){
            int x,y;
            cin>>x>>y;
            visited[x][y]=1;
        }
        TRY(1);
        cout<<dem<<endl;
    }
}
