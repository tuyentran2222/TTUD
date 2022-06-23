#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005
int f,s,g,u,d;//so tang/ xuat phat/ dich/ len/ xuong/
bool visited[MAX];
bool ex[MAX];
vector<int> a[MAX];
vector <int > iDist (MAX , 0);
stack<int> st;
queue<int> q;

int bfs(){
    q.push(g);
    while (!q.empty()){
        int top=q.front();
        q.pop();
        if (top==s) return iDist[s];
        for (int i=0;i<a[top].size();i++){
            int u=a[top][i];
            if ( iDist[u] == 0){
                q.push(u);
                iDist[u] = 1 + iDist[top];
            }
        }
    }
    return iDist[s];
}
int main(){
    cin>>f>>s>>g>>u>>d;
    st.push(g);
    while (!st.empty()){
        int top=st.top();
        st.pop();
        visited[top]=true;
        if (top+d<=f) {
            a[top].push_back(top+d);
            if (visited[top+d]==false) st.push(top+d);
        }
        if (top-u>=1) {
            a[top].push_back(top-u);
            if (visited[top-u]==false) st.push(top-u);
        }

    }


    int res=bfs();
    if (res==0){
        cout<<"use the stairs";
    }
    else cout<<res;
    return 0;
}
