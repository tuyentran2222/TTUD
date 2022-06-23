#include<bits/stdc++.h>
using namespace std;
int n;
int m;
const int MAX=100001;
struct Edge{
    int u;
    int v;
    int w;
    Edge(int _u,int _v,int _w){
        u=_u;v=_v;w=_w;
    }
};
vector<Edge> E;

//disjoint-set
int r[MAX];//hang cua nut v
int p[MAX]; //cha cua nut v
long long rs;

void makeSet(int x){
    p[x]=x;
    r[x]=0;
}

void unify(int x,int y){
    if (r[x]>r[y]) p[y]=x;
    else{
        p[x]=y;
        if (r[x]==r[y]) r[y]+=1;
    }
}
int find(int x){
    if (x!=p[x]) p[x]=find(p[x]);
    return p[x];
}
bool compare(Edge a,Edge b){
    return a.w<b.w;
}
void solve(){
    sort(E.begin(),E.end(),compare);
    for (int i=1;i<=n;i++){
        makeSet(i);
    }
    for (int i=1;i<M;i++){
        int ru=find(E[i].u);
        int rv=find(E[i].v);

        if (ru!=rv){
            unify(ru,rv);
            T.push_
        }
    }

}
