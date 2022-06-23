#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> ds[100005];
int parent[100005];
queue<int> q;
bool visited[100005];
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int a,b;
    for (int i=1;i<n;i++){
        cin>>a>>b;
        ds[a].push_back(b);
        ds[b].push_back(a);
    }
    for (int i=1;i<=n;i++){
        visited[i]=false;
    }
}
void BFS(int s){
    q.push(s);
    visited[s]=true;
    while (!q.empty()){
        int u=q.front();
        q.pop();
        visited[u]=true;
        for (int i=0;i<=ds[u].size()-1;i++){
            int v=ds[u][i];
            if (!visited[v]){
                parent[v]=u;
                q.push(v);
            }
        }
    }
}
int main(){
    input();
    BFS(1);
    for (int i=2;i<=n;i++){
        cout<<parent[i]<<" ";
    }
    return 0;
}
