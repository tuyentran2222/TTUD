#include<bits/stdc++.h>
using namespace std;

int N; //numbers of point
int K; //so chang
int c[3005];//amount of good
int a[3005];//amount of energy
int dp[3005][105];
void input(){
    cin>>N>>K;
    for (int i=1;i<=N;i++){
        cin>>c[i];
    }
    for (int i=1;i<=N;i++){
        cin>>a[i];
    }
}

void solve(){
    dp[1][0]=c[1];
    int res=0;

    for (int i=2;i<=N;i++){
        for (int k=1;k<=i,k<=K;k++){
            for (int j=i-1;j>=1;j--){
                    if (j+a[j]>=i){
                        //if (dp[j][k-1]==0) continue;
                        dp[i][k]=max(dp[j][k-1]+c[i],dp[i][k]);
                    }
            }
        }
    }

    for (int j=0;j<=K;j++){
        res=max(res,dp[N][j]);
    }
    for (int i=1;i<=N;i++){
        for (int j=1;j<=K;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    if (res==0) cout<<-1;
    else cout<<res;

}
int main(){
    input();
    solve();
}
