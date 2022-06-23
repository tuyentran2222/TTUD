#include<bits/stdc++.h>
using namespace std;
int n;//so dinh
int m;//so canh
typedef pair<int,int> ii;
struct Arc{
    int node;
    int w;
    Arc(int _node, int _w){
        node=_node;
        w =_w;
    }
};
vector<Arc> A[100005];
int s,t;
int d[100005];

void solve(){
    for (int i=1;i<=n;i++) d[i]=INT_MAX;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    d[s]=0;
    pq.push(make_pair(d[s],s));

    while (!pq.empty()){
        ii p=pq.top();
        pq.pop();
        int u=p.second;
        if (u==t) break;
        for (int i=0;i<A[u].size();i++){
            Arc a=A[u][i];
            int v=a.node;
            int w=a.w;
            if (w+d[u]<d[v]){
                d[v]=d[u]+w;
                pq.push(make_pair(d[v],v));
            }
        }
    }
    if (d[t]==INT_MAX) cout<<-1;
    else cout<<d[t];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int a,b,c;
    for (int i=1;i<=m;i++){
        cin>>a>>b>>c;
        Arc ar=Arc(b,c);
        A[a].push_back(ar);
    }
    cin>>s>>t;
    solve();

    return 0;
}

