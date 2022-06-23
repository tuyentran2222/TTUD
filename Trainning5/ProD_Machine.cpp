#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> a;
#define MAX_V 2000005
int L[MAX_V];
int R[MAX_V];
bool compare(pair<int,int> m,pair<int,int> k){
    return m.second<k.second;
}
void input(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    pair<int,int> c;
    for (int i=0;i<n;i++){
        cin>>c.first>>c.second;
        a.push_back(c);
    }
    for (int i=0;i<MAX_V;i++){
        L[i]=0;
        R[i]=0;
    }

    sort(a.begin(),a.end(),compare);
}
int solve(){
    L[a[0].second]=a[0].second-a[0].first;
    L[0]=0;
    int j=0;
    for (int i=1;i<=a[n-1].second;i++){
        //cout<<i<< " "<<a[j].second<<endl;
        if (i<a[j].second){
            L[i]=L[i-1];
        }
        else {
            L[i]=max(L[i-1],a[j].second-a[j].first);
            j++;
        }
    }

    j=n-1;
    for (int i=a[n-1].second;i>=1;i--){
        //cout<<j<<" "<<i<<" "<<a[j].first<<endl;
        if (i>a[j].first){
            continue;
        }
        else {
            if (L[a[j].first]==0) break;
            R[i]=L[a[j].first]+a[j].second-a[j].first;
            j--;
        }
    }

    int ans=0;
    for (int i=1;i<=a[n-1].second;i++) ans=max(ans,R[i]);
    if (ans==0) cout<<-1;
    else cout<<ans;
}

int main(){
    input();
    solve();
}
