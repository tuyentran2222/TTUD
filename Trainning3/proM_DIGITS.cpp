#include <bits/stdc++.h>
using namespace std;
const int N1=9;
const int k=7;
int check[10];
int kq[8];
int N;
int cnt=0;
int TRY(int i){
    for (int j=1;j<=N1;j++){
        if (check[j]==0){
            kq[i]=j;
            check[j]=1;
            if (i==(k)){

                if (100*kq[1]+10*kq[2]+kq[3]-62-100*kq[7]+1000*kq[4]+100*kq[5]+10*kq[6]+kq[3]==N)
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
    cin>>N;
    for (int i=1;i<10;i++){
        check[i]=0;
    }
    TRY(1);
    cout<<cnt;
}
