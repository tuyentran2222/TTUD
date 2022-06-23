#include<bits/stdc++.h>
using namespace std;
long long fac(long long n, long long mod){
    long long m=1;
    for (int i=2;i<=n;i++){
        m=((m%mod)*(i%mod))%mod;
    }
    return m;
}
int main(){
    long long n,k;
    cin>>n>>k;
    long long mod=1000000007;
    long long ts= fac(n,mod);
    long long ms =fac(k,mod)* fac(n-k,mod);
     cout<<ts<<" "<<ms<<endl;
     for (int i=1;i<=k-2;i++){
        ms=(ms*(ms%mod));
     }
     cout<<((ts%mod)*(ms%mod))%mod;

}
