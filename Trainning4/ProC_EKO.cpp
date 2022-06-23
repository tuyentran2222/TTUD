#include<bits/stdc++.h>
using namespace std;
unsigned long long n;
unsigned long long M;
unsigned long long maxH=0;
unsigned long long tong,tmp;
unsigned long long a[1000005];
long long h=0;
int  test(unsigned long long h ){
    unsigned long long currLen=0;
    if (h==0) return 0;
    for (unsigned long long i=1;i<=n;i++){
        if (a[i]>h) currLen+=(a[i]-h);
    }
    if (currLen==M) return 1 ;
    else if (currLen>M) return 2;
    else return 0;

}
void solve(){
    ios::sync_with_stdio(false);
    unsigned long long l=0;
    unsigned long long r= maxH;
    //cout<<l<<" "<<r<<endl;
    long long m;
    while(l<=r){
        m=(l+r)/2;
        //cout<<"loop "<<l<<" "<<m<<" "<<r<<endl;
        if (test(m)==1){
            h=m;
            break;
        }
        else if (test(m)==2){
            l=m+1;
            if (m>h) h=m;
        }
        else {
            r=m-1;

        }

    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>M;
    tong=0;
    for (unsigned long long i=1;i<=n;i++){
        cin>>a[i];
        maxH=max(maxH,a[i]);
    }
    solve();
    cout<<h;

}
