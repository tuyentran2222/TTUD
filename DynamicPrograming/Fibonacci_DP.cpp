#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int mem[MAX];
int F(int n){
    if (n<=1) {
        mem[n]=1; return 1;
    }
    if (mem[n]>0) return mem[n];
    mem[n]= F(n-1)+F(n-2);
    return mem[n];
}
int main(){
    for (int i=0;i<MAX;i++){
        mem[i]=0;
    }
    //cout<<F(125)<<endl;
    mem[0]=1;
    mem[1]=1;
    int i;
    for ( i=2;i<=10;i++){
        mem[i]=mem[i-1]+mem[i-2];
    }
    cout<<mem[10]<<endl;
    return 0;
}
