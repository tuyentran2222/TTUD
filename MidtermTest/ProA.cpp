
#include<bits/stdc++.h>
using namespace std;
long long x[1005];
long long y[1005];
int T;
int n;
long long res=0;
bool compare(long long a,long long b){
    return a>b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    for (int i=1;i<=T;i++){
        res=0;
        cin>>n;
        for (int j=1;j<=n;j++){
            cin>>x[j];
        }
        for (int j=1;j<=n;j++){
            cin>>y[j];
        }
        sort(x+1,x+n+1,compare);

        sort(y+1,y+n+1);

        for (int j=1;j<=n;j++){
            res=x[j]*y[j]+res;
        }
        cout<<"Case #"<<i<<": "<<res<<endl;

    }

    return 0;
}
