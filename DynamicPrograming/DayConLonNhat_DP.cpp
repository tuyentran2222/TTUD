#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
//s[i] la tong day con lon nhat ket thuc tai a[i]
int S0[MAX];//tong day con chan lon nhat
int S1[MAX];//tong day con le lon nhat
int a[MAX];
int n;
bool solved0[MAX];// true: neu tong chan ton tai
bool solved1[MAX];// true: neu tong le S1[i] ton tai
void input(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        solved0[i]=false;
        solved1[i]=false;
    }
}
int solve(int i){
   if (a[i]%2==0){
    S0[1]=a[1];
    solved0[1]=true;
    solved1[1]=false;
   }
   else{
    S1[1]=a[1];
    solved0[1]=false;
    solved1[1]=true;
   }
   for (int i=2;i<=n;i++){
        if (a[i]%2==0){
            if (solved0[i-1]){
                S0[i]=max(a[i],S0[i-1]+a[i]);
                solve0[i]=true;
            }
            else{
                S0[i]=a[i];
            }
            if (solved1[i-1]){
                S1[i]=S1[i-1]+a[i];
                solved1[i]=true;
            }
            else solved1[i]=false;

        }
        else{
            if (solved1[i-1]){
                S0[i]=S1[i-1]+a[i];
                solve0[i]=true;
            }
            else{
               solved0[i]=false;
            }
            if (solved0[i-1]){
                S1[i]=max(a[i],a[i]+S0[i-1]);
            }
            else S1[i]=a[i];
            solved1[i]=true;
        }
   }
   for (int i=1;i<=n;i++){
    if (solve0[i]&&ans<S0[i]){
        ans=S0[i];
    }
   }
}

int main(){
    input();
    solve();

    return 0;
}
