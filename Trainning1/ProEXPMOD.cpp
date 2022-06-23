
#include<bits/stdc++.h>
using namespace std;
unsigned long long Expmod( unsigned long long a, unsigned long long b, unsigned long long mod) {
    unsigned long long result = 1;
    for ( unsigned long long i=b; i; i>>=1 ) {
        if ( i & 1 ) result= ((result % mod) * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
    }
    return result;
}

int main()
{
    unsigned long long a,b,sbc;
    cin>>a>>b;
    sbc=1000000007;
    unsigned long long res= Expmod(a,b,sbc);
    cout<<res<<endl;
    return 0;
}
