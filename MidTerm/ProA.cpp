#include<bits/stdc++.h>
using namespace std;
const int N1=9;
const int k=6;
int check[10];
int kq[7];
int N;
int cnt=0;
int TRY(int i){
    for (int j=0;j<=N1;j++){
        if (j==0&&(i==1||i==2)) continue;
        if (check[j]==0){
            kq[i]=j;
            check[j]=1;
            if (i==(k)){

                if (100000*kq[1]+10001*kq[2]+1000*kq[3]+100*kq[4]+10*kq[5]+1100*kq[2]+10*kq[6]+kq[3]==N)
                {
                    cnt++;
                }

            }
            else TRY(i+1);
            check[j]=0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for (int i=1;i<10;i++){
        check[i]=0;
    }
    TRY(1);
    cout<<cnt;

    return 0;
}
