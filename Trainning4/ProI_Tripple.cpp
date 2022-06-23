#include<bits/stdc++.h>
using namespace std;
#define MAX_N 5000
#define MAX_A 100000
int a[MAX_N+5];
int xh[MAX_A+5];
int K;
int N;
long long dem=0;

int main(){
    cin>>N>>K;
    for (int i=1;i<=MAX_A;i++){
        xh[i]=0;
    }
    for (int i=1;i<=N;i++){
        cin>>a[i];
        xh[a[i]]=i;
    }
    for (int i=1;i<=N-2;i++){
        for (int j=i+1;j<=N-1;j++){
            if (a[i]+a[j]>=K) continue;
            else {
                int z=K-a[i]-a[j];
                if (xh[z]>j){
                    dem++;
                }
            }
        }
    }
    cout<<dem;
}
