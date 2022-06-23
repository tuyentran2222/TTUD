#include<bits/stdc++.h>
using namespace std;
int N;//so chi nhanh
int M;//so cua hang
int a[105];//so nhan vien moi chi nhanh
long long L[505][105]; //L[i][j] so cach chia i cua hang cho j chi nhanh
void input(){
    cin>>N>>M;
    for (int i=1;i<=N;i++){
        cin>>a[i];
    }
}
void solve(){
    long long q=1000000007;
    for (int i=1;i<M;i++){
        if (i%a[1]==0) L[i][1]=1;
    }

    for (int i=1;i<=M;i++){
        for (int j=1;j<=N;j++){
            for (int k=1;k<=(i/a[j]);k++){
                L[i][j]=(L[i-a[j]*k][j-1]%q+L[i][j]%q)%q;

            }
        }

    }
    /*for (int i=1;i<=M;i++){
        for (int j=1;j<=N;j++){
            cout<<L[i][j]<<" ";
        }
        cout<<endl;
    }*/

    cout<<L[M][N];
}


int main(){
    input();
    solve();

}
