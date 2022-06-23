#include<bits/stdc++.h>
using namespace std;
#define MAX_N 12
int H,W;
int N;
int h[MAX_N+1];
int w[MAX_N+1];
int visited[31][31];
int r[31];
int c[31];
int res=0;
int check(int i,int j,int k){
    for (int i1=i;i1<i+h[k];i1++){
        for (int i2=j;i2<j+w[k];i2++){
            if (visited[i1][i2]!=0) return false;
        }
    }
    return true;
}
int TRY(int k){
    for (int i=0;i<=H-h[k];i++){
        for (int j=0;j<=W-w[k];j++){
            if (check(i,j,k)){
                r[i]=i;
                c[j]=j;
                visited[i][j]=k;
                for (int i1=i;i1<i+h[k];i1++){
                    for (int i2=j;i2<j+w[k];i2++){
                        visited[i1][i2]=k;
                    }
                }
                if (k==N) {res=1;return res;}
                else TRY(k+1);
                for (int i1=i;i1<i+h[k];i1++){
                    for (int i2=j;i2<j+w[k];i2++){
                        visited[i1][i2]=0;
                    }
                }
                visited[i][j]=0;
            }
        }
    }
    return res;
}
int main(){
    cin>>H>>W;
    cin>>N;
    for (int i=1;i<=N;i++){
        cin>>h[i]>>w[i];
    }
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            visited[i][j]=0;
        }
    }
    cout<<TRY(1);

}
