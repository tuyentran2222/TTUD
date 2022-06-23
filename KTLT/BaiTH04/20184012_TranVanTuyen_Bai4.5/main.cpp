#include <iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1);
    while(!S.empty()){
        int top1=S.top();
        S.pop();
        if( visited.at(top1)) continue;
        visited.at(top1)=true;
        cout<<top1<<" "<<endl;
        list<int>::iterator it = adj[top1].begin()++;
        if (adj[top1].size()){
            for (it=--adj[top1].end(); it!= adj[top1].begin();it-- ){
            if(visited[*it]==false){
                S.push(*it);
                //cout<<"x="<<*it<<endl;
            }
        }
        it=adj[top1].begin();
        //cout<<"X="<<*it<<endl;
        if(visited[*it]==false) S.push(*it);
        }
    }
}
int main()
{   cout<<"Ho va ten:Tran Van Tuyen"<<endl;
    cout<<"MSSV:20184012"<<endl;
    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    dfs(adj);

    return 0;
}
