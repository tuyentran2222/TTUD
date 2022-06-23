#include <bits/stdc++.h>
using namespace std;
int n,k;
const int MAX=20;
int c[2*MAX+1][2*MAX+1]; //khoang cach giua hai diem
int visited[2*MAX+3];
int cmin=INT_MAX;
int best=INT_MAX;//gia tri tot nhat hien tai
int f=0;//gia tri tam thoi
int sng=0;
int x[2*MAX+2];
int curr;
bool sosanh(int m1,int m2){
    return c[curr][m1]<=c[curr][m2];
}
vector<int> UCV(int k1){
    curr=x[k1-1];
    vector<int> c;
    if (k1==k){
        for (int i=1;i<=n;i++){
            if ((visited[i]==1) &&(visited[i+n]==0)){
                c.push_back(i+n);
            }
            sort(c.begin(),c.end(),sosanh);
            for (int i=1;i<=c.size();i++){
            cout<<c[i-1]<<" ";
        }
        cout<<endl;
        }
        return c;
    }
    else{
        for (int i=1;i<=n;i++){
            if ((visited[i]==0) ) c.push_back(i);
            if ((visited[i]==1) &&(visited[i+n]==0)){
                c.push_back(i+n);
            }
        }
        sort(c.begin(),c.end(),sosanh);
        for (int i=1;i<=c.size();i++){
            cout<<c[i-1]<<" ";
        }
        cout<<endl;
        return c;
    }
}

void TRY(int stt){
    vector<int> vect=UCV(sng);
    int size1=vect.size();

    for (int i=0;i<size1;i++){
        x[stt]=vect[i];
        visited[vect[i]]=1;
        if (vect[i]<=n) sng++;
        else sng--;
        f=f+c[x[stt-1]][x[stt]];

        if(stt==2*n){
            if (f+c[x[stt]][0]<best) best=f+c[x[stt]][0];
        }
        else {
            if (f+(2*n-stt)*cmin<best) TRY(stt+1);
        }
        f=f-c[x[stt-1]][x[stt]];
        visited[vect[i]]=0;
        if (vect[i]<=n) sng--;
        else sng++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;

    for (int i=0;i<=2*n+1;i++){
        visited[i]=0;
    }

    for (int i=0;i<=2*n;i++){
        for (int j=0;j<=2*n;j++){
            cin>>c[i][j];
            if (c[i][j]==0) c[i][j]=INT_MAX;
            cmin=min(cmin,c[i][j]);

        }
    }
    //cout<<"cmin=" <<cmin<<endl;
    x[0]=0;
    visited[0]=1;
    TRY(1);
    cout<<best;
}
