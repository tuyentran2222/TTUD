#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,b;
    int a[200005];
    int prefix[200005];//max a[1]->a[j]
    int suffix[200005];//max a[n]->a[i]
    cin>>n>>b;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    prefix[1]=a[1];
    for (int i=2;i<=n;i++){
        prefix[i]=max(prefix[i-1],a[i]);
    }
    //max sufix
    suffix[n]=a[n];
    for (int i=n-1;i>=1;i--){
        suffix[i]=max(suffix[i+1],a[i]);
    }
    int result=-1;

    for (int i=2;i<=n;i++){
        if (prefix[i-1]-a[i]>=b &&suffix[i+1]-a[i]>=b){
            int tmp=prefix[i]+suffix[i]-2*a[i];
            result=max(result,tmp);
        }
    }
    cout<<result;

}
