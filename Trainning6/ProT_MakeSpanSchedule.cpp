#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
int n;
int m;
struct Arc{
    int v;
    int w;
    Arc(int _v, int _w){
        v=_v;
        w=_w;
    }
};
int duration[MAX];
vector<Arc> ds[MAX];
int d[MAX];//ban bac vao
vector<int> L;//sap xep topo
int F[MAX];//thoi gian som nhat task v bat dau
int ans;
void input(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>duration[i];
    }
    int u,v;
    for (int i=1;i<=m;i++){
        cin>>u>>v;
        ds[u].push_back(Arc(v,duration[u]));
        d[v]++;
    }
}
void topoSort(){
    queue<int> q;
    for (int i=1;i<=n;i++){
        if (d[i]==0) q.push(i);
    }
    while (!q.empty()){
        int u= q.front();
        q.pop();
        L.push_back(u);
        for (int i=0;i<ds[u].size();i++){
            int v= ds[u][i].v;
            int w= ds[u][i].w;
            d[v]--;
            if (d[v]==0) q.push(v);
        }
    }
}

void solve(){
    for (int i=1;i<=n;i++){
        F[i]=0;
    }
    for (int i=0;i<L.size();i++){
        int u=L[i];
        ans= max(ans,F[u]+duration[u]);
        for (int j=0;j<ds[u].size();j++){
            int v= ds[u][j].v;
            int w= ds[u][j].w;
            F[v]=max(F[v],F[u]+w);
        }
    }
    cout<<ans;

}



int main(){
    input();
    topoSort();
    solve();
    return 0;
}
