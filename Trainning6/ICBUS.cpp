#include<bits/stdc++.h>
using namespace std;
int k;// so luong kich ban
int n;//number of nodes
vector<int> a[5005];
int d[5005];
int c[5005];
int cnt[5005][5005];//so luong thanh pho it nhat can di qua giua (u,v)
bool visited[5005];
int cmin[5005];//chi phi nho nhat de di chuyen
int input(){
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>c[i]>>d[i]; //gia ve so thanh pho di qua
    }
    int u,v;
    for (int i=1;i<=m;i++){
        cin>>u>>v;
        ds[u].push_back(v);
        ds[v].push_back(u);
    }
}

int bfs(int root){
    queue<int> q;
    q.push(root);
    while (!q.empty()){
        int u=q.front();
        q.pop();

        visited[u]=true;
        for (int v: a[u]){
            if (visited[v]) continue;
            cnt[root][v]=cnt[root][u]+1;
        }

    }

}
bool get_u_cmin(){
    for (int i=1;i<=n;i++){
        if (cmin[i])
    }
}
void dijkstra(int root){
    memset(cmin,INT_MAX,sizeof(cmin));
    while (get_u_cmin()){

    }

}
int main(){
    input();
    for (int u=1;u<=n;u++){
        bfs(u);
    }
}
