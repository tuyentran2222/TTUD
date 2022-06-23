#include<bits/stdc++.h>
using namespace std;
int N;//number of nodes
int M;//number of edges
bool visited[100005];
vector<int> ds[100005];
queue<int> Q;
int cnt=0;
void input(){
    cin>>N>>M;
    int a,b;
    for (int i=1;i<=M;i++){
        cin>>a>>b;
        ds[a].push_back(b);
        ds[b].push_back(a);
    }
    for (int i=1;i<=N;i++){
        visited[i]=false;
    }
}

void BFS(int s){
    Q.push(s);
    while (!Q.empty()){
        int top=Q.front();
        Q.pop();
        if (visited[top]) continue;
        visited[top]=true;
        for (int i=0;i<ds[top].size();i++){
            Q.push(ds[top][i]);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    for (int i=1;i<=N;i++){
        if (!visited[i]){
            cnt++;
            BFS(i);
        }
    }
    cout<<cnt;
}

