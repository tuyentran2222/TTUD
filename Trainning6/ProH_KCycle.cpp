#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> ds[100005];
int parent[100005];
queue<int> q;
bool visited[100005];
int dem=0;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    int a,b;
    for (int i=1;i<=m;i++){
        cin>>a>>b;
        ds[a].push_back(b);
        ds[b].push_back(a);
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
                parent[v]=parent[u]+1;
                q.push(v);

            }
            else {
                if (parent[u]+parent[v]+1==k) dem++;
            }
        }
    }
}
int main(){
    input();
    for (int i=1;i<=n;i++){
        BFS(i);
        for (int j=1;j<=n;j++){
            visited[j]=false;
            parent[j]=0;
            q=queue<int>();
        }
    }
    cout<<dem;
    return 0;
}
