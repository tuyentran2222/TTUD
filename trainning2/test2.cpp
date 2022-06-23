#include<bits/stdc++.h>
using namespace std;
int x[100];
int visited[100];
int n,K;
int T;
int cnt=0;
int a[100][100];
void solotion(){
    cnt++;
    for (int i=1;i<=n;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
bool check(int v,int k){
    if (visited[v]==1) return false;
    for (int i=1;i<=k-1;i++){
        if (a[v][x[i]]==1) return false;
    }
    return true;
}
void Try(int k){
    for (int v=1;v<=n;v++){
        if (check(v,k)){
            x[k]=v;
            visited[v]=1;
            if (k==n) solotion();
            else Try(k+1);
            visited[v]=0;
        }
    }
}
int main(){
    cin>>n;
    cin>>K;
    for (int i=1;i<n;i++){
        visited[i]=0;
    }
    int p,q;
    for (int i=1;i<=K;i++){
        for (int j=1;j<=K;j++){
            a[i][j]=0;
        }
    }
    for (int i=1;i<=K;i++){
        cin>>p>>q;
        a[p][q]=1;
    }

    Try(1);
    cout<<cnt;
}
