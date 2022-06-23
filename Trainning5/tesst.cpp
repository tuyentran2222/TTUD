#include<bits/stdc++.h>
using namespace std;
int n;
int K;
int c[3005];//so luong hang
int a[3005]; //nang luong nhan duoc
int dp[3005][105]; //tong hang hoa nhieu nhat voi nang luongk

void input(){
    cin>>n>>K;
    for (int i=1;i<=n;i++){
        cin>>c[i];
    }
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
}
int solve(){
    dp[1][0]=c[1];
    for (int i=2;i<=n;i++){
        for (int j=1;j<=i,j<=K;j++){
            for (int k=i-1;k>=1;k--){
                if (a[k]+k>=i){
                    if (dp[k][j-1]==0) continue;
                        dp[i][j]=max(dp[k][j-1]+c[i],dp[i][j]);
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=K;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 1;
}
int main(){
    input();
    solve();
    return 0;
}
