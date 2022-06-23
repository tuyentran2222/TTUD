#include<bits/stdc++.h>
using namespace std;
int x[100];
int n,M;
int T;
int cnt;
void solotion(){
    cnt++;
    cout<<cnt<<": ";
    for (int i=1;i<=n;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
bool check(int v,int k){
     if (k<n)return true;
     return T+v==M;
}
void Try(int k){
    for (int v=1;v<=M-T-(n-k);v++){
        if (check(v,k)){
            x[k]=v;
            T=T+v;//update
            if (k==n) solotion();
            else Try(k+1);
            T=T-v;
        }
    }
}
int main(){
    cin>>n;
    cin>>M;
    Try(1);
}
