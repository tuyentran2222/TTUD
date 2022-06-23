#include<bits/stdc++.h>
using namespace std;
int n;
int d[16];
int check[16];
int q[16];
int best=INT_MAX;
int curr=0;
int TRY(int k){
    int m=n;
    if (n>10) m=8;
    for (int i=1;i<=m;i++){
        if (q[i]>=d[k]){
            int temp=q[i];
            q[i]=q[i]-d[k];
            if (temp==6) curr++;
            if (k==n){
                if (curr<best) best=curr;
            }
            if (curr<best) TRY(k+1);
            q[i]=q[i]+d[k];
            if (temp==6) curr--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>d[i];
        check[i]=0;
        q[i]=6;
    }
    TRY(1);
    cout<<best;


    return 0;
}
