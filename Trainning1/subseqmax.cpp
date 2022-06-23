#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n+1];

    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxsum = 0;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        if (sum < 0) sum = 0;
        maxsum = max(sum, maxsum);
    }
    cout<<maxsum;





}
