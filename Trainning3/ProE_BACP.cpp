#include <bits/stdc++.h>
using namespace std;
int n,m;
#define MAX 16
int c[MAX+1];
int depen[MAX+1][MAX+1];
int best=INT_MAX;
int f=0;
int x[MAX+1];
int visited[MAX+1];
int kq[6];
int max_sub(int* arr){
    int max_z = 0;
    for(int i = 0; i <= m; i++){
        if(arr[i] > max_z)
            max_z = arr[i];
    }
    return max_z;
}
int check(int k,int x){
    if (visited[k]==0){
        for (int i=1;i<k;i++){
            if (depen[i][k]&&visited[i]>x) return false;
        }
        return true;
    }
    return false;
}
int TRY(int k){
    for(int i=1;i<=m;i++){
        if (check(k,i)){
            visited[k]=i;
            kq[i]=kq[i]+c[k];
            if (k==n){
                f=max_sub(kq);
                if (f<best) best=f;
            }
            else {
                if (kq[i]<best)
                    TRY(k+1);
            }
            kq[i]=kq[i]-c[k];
            visited[k]=0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>depen[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        visited[i]=0;
    }
    TRY(1);
    cout<<best;
}
