#include <iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // Bắt đầu từ đỉnh số 1
    while(!Q.empty()){
        int top1=Q.front();
        Q.pop();
        if( visited.at(top1)) continue;
        visited.at(top1)=true;
        cout<<top1<<" "<<endl;
        list<int>::iterator it = adj[top1].begin()++;
        if (adj[top1].size()){
            for (it=adj[top1].begin(); it!= adj[top1].end();it++ ){
            if(visited[*it]==false){
                Q.push(*it);
                //cout<<"x="<<*it<<endl;
                }
            }
        }
    }
}
int main(){
    cout<<"Ho va ten:Tran Van Tuyen"<<endl;
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
    bfs(adj);

    return 0;
}
