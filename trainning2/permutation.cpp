#include<bits/stdc++.h>
using namespace std;
int x[100];
int visited[100];
int n,K;
int T;
int cnt=0;
map<int,int> map1;
void solotion(){
    cnt++;
    for (int i=1;i<=n;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
bool check(int v,int k){
     if ((visited[map1[v]]||map1[v]==0)&&visited[v]==0) return true;
     return false;
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
    int a,b;
    for (int i=1;i<=K;i++){
        map1[i]=0;
    }
    for (int i=1;i<=K;i++){
        cin>>a>>b;
        map1[b]=a;
    }
    Try(1);
    cout<<cnt;
}
