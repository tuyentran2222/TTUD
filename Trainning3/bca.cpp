#include <bits/stdc++.h>
using namespace std;
int n,m;
int result=INT_MAX;
int can[10][30], conflict[30][30], sub[30],cnt[10];
//m: so giao vien   n:so khoa hoc
//can[i][j] :giao vien i co the day duoc mon hoc j hay khong
//conflict: xung dot
//sub: mon hoc da giao
//cnt: tong so mon hoc da giao cho giao vien i
int maxvalue(int *arr){
    int max_z = 0;
    for(int i = 0; i < m; i++){
        if(arr[i] > max_z)
            max_z = arr[i];
    }
    return max_z;
}

bool check(int t,int i){
    if (can[i][t]&&sub[t]==-1){
        for (int j=0;j<n;j++){
            if (sub[j]==i){
                if (conflict[j][t]|| conflict[t][j]){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}



void BCA(int k){
    if (k==n){
        int maxvalue1=maxvalue(cnt);
        if (maxvalue1<result) result=maxvalue1;
    }
    for (int i=0;i<m;i++){
        if (check(k,i)){
            sub[k]=i;
            cnt[i]++;
            if (cnt[i]<result) BCA(k+1);
            cnt[i]--;
            sub[k]=-1;
        }
    }
}

int main(){
    cin>>m>>n;
    int k;
    for(int i = 0; i < m; i++){
        for (int j=0;j<n;j++){
            can[i][j]=0;
        }
    }
    for(int i = 0; i < n; i++){
        for (int j=0;j<n;j++){
            conflict[i][j]=0;
        }
    }

    for(int i = 0; i < n; i++){
        sub[i]=-1;
    }

    for(int i = 0; i < m; i++) cnt[i] = 0;

    for (int i=0;i<m;i++){
        cin>>k;
        for (int j=0;j<k;j++){
            int z;
            cin>>z;
            can[i][z-1]=1;
        }
    }

    cin>>k;
    for (int z=0;z<k;z++){
        int i,j;
        cin>>i>>j;
        conflict[i-1][j-1]=1;
    }
    BCA(0);
    if (result==INT_MAX) cout<<-1;
    else
    cout<<result;

}
