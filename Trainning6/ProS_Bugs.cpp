#include<bits/stdc++.h>
using namespace std;
int k;// so luong kich ban
int N;//number of nodes
int M;//number of edges
bool visited[2005];
vector<int> ds[2005];
vector<int> x;
vector<int> y;
int color[2005];
queue<int> q;


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
    cin>>k;
    int dem=0;
    while (dem!=k){
        dem++;
        cin>>N>>M;
        int a,b;
        q=queue<int>();
        for (int i=1;i<=N;i++){
            ds[i].clear();
        }
        for (int i=1;i<=M;i++){
            cin>>a>>b;
            ds[a].push_back(b);
            ds[b].push_back(a);
        }
        for (int i=1;i<=N;i++){
            visited[i]=0;
            color[i]=-1;
        }
        int res=1;
        for (int i=1;i<=N;i++){
            if (color[i]==-1){
                if (isBipartite(i)==0) {
                    res=0;
                    break;
                }
            }
        }

        cout<<"Scenario #"<<dem<<":"<<endl;
        if (res==0) cout<<"Suspicious bugs found!"<<endl;
        if (res==1) cout<<"No suspicious bugs found!"<<endl;

    }
    memset(color,-1,sizeof(color));
    return 0;

}
