#include <bits/stdc++.h>
using namespace std;
int n,K,Q;
//n: so khach hang
//K: so xe
//Q: khoi luong max
int d[10+1];//so luong thung moi khach hang yeu cau
int visited[5+1];//luu tru xe nao cho hang den khach thu i
int sum[5+1];//tong so thung cua xe i
int sumPerson[5+1];
unsigned long long count1=0;
unsigned long long giaithua(unsigned long long n){
    if (n==0) return 0;
    if (n==1) return 1;
    return giaithua(n-1)*n;
}
int TRY(int k){
    for (int i=1;i<=K;i++){
        if (sum[i]+d[k]<=Q){
            sumPerson[i]++;
            sum[i]=sum[i]+d[k];
            if (k==n){
                unsigned long long gt=1;
                for (int j=1;j<=K;j++){
                    gt=gt*giaithua(sumPerson[j]);
                }
                count1+=gt;
            }
            else TRY(k+1);
            sumPerson[i]--;
            sum[i]=sum[i]-d[k];
        }
    }
}
int main(){
    cin>>n>>K>>Q;
    for (int i=1;i<=n;i++){
        cin>>d[i];
    }
    for (int i=1;i<=K;i++){
        sumPerson[i]=0;
        sum[i]=0;
    }
    TRY(1);
    cout<<(count1/giaithua(K))%(100000007);

}
