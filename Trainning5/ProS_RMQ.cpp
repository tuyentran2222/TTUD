#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
int m;
vector<pair<int,int>> b;
int mi[1000005];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    pair<int,int> c;
    for (int i=0;i<m;i++){
        cin>>c.first>>c.second;
        b.push_back(c);
    }
    mi[0]=a[0];
    for (int i=1;i<n;i++){
        mi[i]=min(mi[i-1],a[i]);
    }

    unsigned long long Q=0;
    for (int i=0;i<m;i++){
        int f=b[i].first;
        int s=b[i].second;
        if (mi[f]!=mi[s]){
            Q=Q+mi[s];
        }
        else{
            int q=INT_MAX;
            for (int j=b[i].first;j<=b[i].second;j++){
                q=min(a[j],q);
            }
            Q=Q+q;
        }
    }
    cout<<Q;
}

