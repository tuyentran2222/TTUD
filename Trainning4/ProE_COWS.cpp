#include<bits/stdc++.h>
using namespace std;
int N,C;
int t;
int a[100005];
int test(int m){
    int c=0;
    int curr=a[1];
    for (int i=2;i<=N;i++){
        if (a[i]-curr<m) continue;
        else {
            curr=a[i];
            c++;
        }
    }
    if (c>=C-1) return 1;
    return 0;

}
int solveCows(){
    int l=1;
    int r=a[N];
    int cur=0;
    int m;
    while(l<r){
        int m=(l+r)/2;
        if (test(m)==1){
            if(m>cur) cur=m;
            l=m+1;
        }
        else {
            r=m;
        }
    }
    return cur;

}

int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    for (int j=1;j<=t;j++){
        cin>>N>>C;
        for (int i=1;i<=N;i++){
            cin>>a[i];
        }
        sort(a+1,a+N+1);
        cout<<solveCows()<<endl;
    }
    return 0;
}
