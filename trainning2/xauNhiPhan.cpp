#include<bits/stdc++.h>
using namespace std;
const int N=100;
int x[N];
int n;
int cnt;
void solotion(){
    cnt++;
    for (int i=0;i<n;i++){
        cout<<x[i];
    }
    cout<<endl;
}
bool check(int v,int k){
     return true;
}
void Try(int k){
    for (int v=0;v<=1;v++){
        if (check(v,k)){
            x[k]=v;
            if (k==n) solotion();
            else Try(k+1);
            x[k]=0;

        }
    }
}
int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        x[i]=0;
    }
    Try(0);
}
