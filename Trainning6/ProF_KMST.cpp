#include<bits/stdc++.h>
using namespace std;

int N;
int M;
int K;
typedef struct E{
    int res;
    int des;
    int w;
}E1;

bool compare(E1 a,E1 b){
    return a.w>b.w;

}
vector<E1> vt;
void input(){
    cin>>N>>M>>K;
    int a,b,c;
    E1 d;
    for (int i=1;i<=M;i++){
        cin>>d.res>>d.des>>d.w;
        vt.push_back(d);
    }
    cout<<"endl";
    sort(vt.begin(),vt.end(),compare);
    for (int i=1;i<=M;i++){
        cout<<vt[i].res<<" "<<vt[i].des<<" "<<vt[i].w<<endl;
    }
}

int main(){
    input();
    return 0;
}
