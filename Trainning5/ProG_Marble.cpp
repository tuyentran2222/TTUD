#include<bits/stdc++.h>
using namespace std;
int W;
int H;
int N;
vector<pair<int,int>> vec;
int L[605][605];
void input(){
    cin>>W>>H;
    cin>>N;
    pair<int,int> c;
    c.first=0;
    c.second=0;
    vec.push_back(c);//them (0,0) vao vi tri 0
    for (int i=1;i<=N;i++){
        cin>>c.first>>c.second;
        vec.push_back(c);
    }
}

void solve(){
    for (int i=1;i<=W;i++){
        for (int j=1;j<=H;j++){
            L[i][j]=i*j;
            for (int k=1;k<=N;k++){
                if (vec[k].first<=i&&vec[k].second<=j){
                    int q1=vec[k].first;
                    int q2=vec[k].second;
                    int temp=min(L[i-q1][q2]+L[i][j-q2],L[i-q1][j]+L[q1][j-q2]);
                    L[i][j]=min(temp,L[i][j]);
                }
            }
        }
    }
    /*for (int i=1;i<=W;i++){
        for (int j=1;j<=H;j++){
            cout<<L[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<L[W][H];
}

int main(){
    input();
    solve();
}
