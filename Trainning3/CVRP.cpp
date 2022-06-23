#include <bits/stdc++.h>
using namespace std;
const int N=100;
int n,K;
int Q;
int d[N];

int y[N];
int x[N];
int load[N];
bool visited[N];
int segments;

bool checkX(int c,int k){
    if(v==0) return true;
    if (visited[v]) return false;
    if (load[k]+d[v]>Q) return false;
    return true;
}
void TryX(int s,int k){
    for (int v=0;i<=n;i++){
        if (checkX(v,k)){
            x[s]=v;
            visited[v]=true;
            load[k]+=d[v];
            segments++;
            if (v==0){
                if (k==K){
                    if (segments==n+K){
                        solution();
                    }
                }
                else
                TryX(y[k+1],k+1);

            }
            else{
                TryX(v,k);
            }
            segments--;
            visited[v]=false;
            load[k]-=d[v];

        }
    }
}
void solution(){
    for(int k=1;k<=K;k++){
        cout<<"Route: "<<"0->";
        int s=y[k];
        while (s>0){

        }
    }
}
bool checkY(int v,int k){
    if (visited[v]) return false;
    if (load[k]+d[v]>Q) return false;
    return true;
}



void TryY(int k){
    for (int v=y[k-1]+1;v<=n;v++){
        if (checkY(v,k)){
            y[k]=v;
            visited[i]=true;
            load[k]+=d[v];
            if (k==K){
                TryX(y[1]);
            }
            else{
                TryY(k+1,1);
            }

        }
    }
}

void solve(){
    y[0]=0;
    d[0]=0;
    segments=0;
    for (int k=1;k<=K;k++) load[i]=0;
    for (int k=1;k<=K;k++) visited[i]=0;

}
void input(){
    cin>>n>>K>>Q;
    for (int i=1;i<=n;i++){
        cin>>d[i];
    }
}
int main(){
    input();

}
