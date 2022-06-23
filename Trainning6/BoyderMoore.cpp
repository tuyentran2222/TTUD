#include<bits/stdc++.h>
using namespace std;

string T;
string p;
int last[256];
int solve(){
    for (int i=0;i<256;i++){
        last[i]=0;
    }
    for (int i=p.length()-1;i--;i>=0){
        if (last[p[i]]==0) last[p[i]]=i;
    }
    int s=0;
    int cnt=0;
    int N=T.length();
    int M=p.length();
    while (s<=N-M){
        int j=M-1;
        while (j>=0&&T[j+s]==p[j]){
            j--;
        }
        if (j==-1) {
            cnt++;
            s=s+1;
        }
        else{
            int k=last[T[j+s]];
            s=s+(j-k>1?j-k:1);
        }
    }
    return cnt;
}

int main(){
    getline(cin,p);
    getline(cin,T);
    cout<<solve();
}
