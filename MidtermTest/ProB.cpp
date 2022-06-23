 #include<bits/stdc++.h>
using namespace std;
#define MAX 1006
const int e = 1e9+7;
int dp[MAX][MAX];
string s;

int main(){
    cin>>s;
    int n=s.size();
    s=" "+s;
    dp[0][0]=1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=i;j++){
            if (s[i]=='('&&j>=1) dp[i][j]=dp[i-1][j-1];
            if (s[i]==')') dp[i][j]=dp[i-1][j+1];
            if (s[i]=='?') {
                if (j>=1)
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%e;
                else dp[i][j]=(dp[i - 1][j + 1] )% e;
            }
        }
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[n][0];
    return 0;
}
