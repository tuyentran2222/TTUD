#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> ds[100005];
int cmax=0;
int res[100005];
bool visited[100005];
queue<int> q;
int c;
void input(){
    cin>>n;
    int a,b,w;
    for (int i=1;i<=n-1;i++){
        cin>>a>>b>>w;
        ds[a].push_back(make_pair(b,w));
        ds[b].push_back(make_pair(a,w));
    }

}

int bfs(int s){
    cmax=0;
    for (int i=1;i<=n;i++){
        visited[i]=false;
    }
    q.push(s);
    visited[s]=true;
    res[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        visited[u]=true;
        for (int i=0;i<ds[u].size();i++){
            int v=ds[u][i].first;
            int w=ds[u][i].second;
            if (!visited[v]){
                res[v]=res[u]+w;
                q.push(v);
            }
        }

    }
    for (int i=1;i<=n;i++){
        cmax=max(cmax,res[i]);
        if (cmax==res[i]) c=i;
    }
    return c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    int c1= bfs(2);
    int c2= bfs(c1);
    cout<<cmax;
    return 0;
}
