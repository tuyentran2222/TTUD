#include<bits/stdc++.h>
using namespace std;
int n;
#define MAX 11
int x[MAX+3];
bool visited[MAX+1];
int c[2*MAX+1][2*MAX+1];
int cmin=INT_MAX;
int best=INT_MAX;
int f=0;
int TRY(int k){
    for (int i=1;i<=n;i++){
        if (visited[i]==false){
            x[k]=i;
            visited[i]=true;
            if(k==1){
                f=f+c[0][x[k]]+c[x[k]][x[k]+n];
                //cout<<"f(1)= "<<f<<endl;
            }
            else{
                f=f+c[x[k-1]+n][x[k]]+c[x[k]][x[k]+n];
                //cout<<"f(#1)= "<<f<<endl;
            }
            if (k==n){
                //cout<<"f(n)= "<<f+c[x[k]+n][0]<<endl;
                if (f+c[x[k]+n][0]<best){
                    best=f+c[x[k]+n][0];
                }
            }
            else{
                int g=f+(n-k+1)*cmin;
                if (g<best) TRY(k+1);
            }
            if (k==1){
                f=f-c[0][x[k]]-c[x[k]][x[k]+n];
            }
            else f=f-c[x[k-1]+n][x[k]]-c[x[k]][x[k]+n];
            visited[i]=false;
        }
    }
}

int main(){
    cin>>n;
    for (int i=0;i<=2*n;i++){
        for (int j=0;j<=2*n;j++){
            cin>>c[i][j];
            if (c[i][j]==0) c[i][j]=INT_MAX;
            cmin=min(c[i][j],cmin);
        }
    }
    for (int i=0;i<=MAX;i++){
        visited[i]=false;
    }
    TRY(1);
    cout<<best;

}
