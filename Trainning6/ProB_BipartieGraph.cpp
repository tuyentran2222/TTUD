#include<bits/stdc++.h>
using namespace std;
int N;//number of nodes
int M;//number of edges
bool visited[100005];
vector<int> ds[100005];
vector<int> x;
vector<int> y;
int color[100005];
queue<int> q;


void input(){
    cin>>N>>M;
    int a,b;
    for (int i=1;i<=M;i++){
        cin>>a>>b;
        ds[a].push_back(b);
        ds[b].push_back(a);
    }
    for (int i=1;i<=N;i++){
        visited[i]=0;
        color[i]=-1;
    }
}

int isBipartite(int s){
    color[s]=1;
    q.push(s);
    while (!q.empty()){
        int u=q.front();
        q.pop();
        for (int i=0;i<ds[u].size();i++){
            if (color[u]==color[ds[u][i]]) return 0;
            if (color[ds[u][i]]==-1){
                q.push(ds[u][i]);
                color[ds[u][i]]=1-color[u];
            }
        }

    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    int res=1;
    for (int i=1;i<=N;i++){
        if (color[i]==-1){
            if (isBipartite(i)==0) {
                res=0;
                break;
            }
        }
    }
    cout<<res;

}
