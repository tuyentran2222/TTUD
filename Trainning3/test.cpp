#include <bits/stdc++.h>
using namespace std;
int n,k;
int cnt=0;
int main(){
    cin>>n>>k;
    vector<int> a;
    for (int i=1;i<=n;i++){
        a.push_back(i);
    }
    do{
        cnt++;
        if (cnt==k){
            for (int i=0;i<=n-1;i++){
                cout<<a[i]<<" ";
            }
            break;
        }
    } while(next_permutation(a.begin(),a.end()));
    if (cnt!=k) cout<<-1;
    return 0;
}
