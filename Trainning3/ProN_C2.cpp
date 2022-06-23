#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
//next_permutation
int main(){
    cin>>n;
    int x;
    for (int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    bool test= next_permutation(a.begin(),a.end());
    if (test==true){
        for (int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
    }
    else cout<<-1;
    return 0;

}
