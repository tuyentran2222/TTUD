#include <bits/stdc++.h>
using namespace std;

unsigned long long n, k, m;


//tinh toan
unsigned long long solve(unsigned long long n, unsigned long long k, unsigned long long m) {
    unsigned long long a[1005][1005];
    if(k==0||k==n) return 1;
    else {
        for(unsigned long long i=0;i<=k;i++)
            for(unsigned long long j=i;j<=n;j++)
                if(i==0||i==j)
                    a[i][j]=1;
                else
                    a[i][j]=(a[i][j-1]%m + a[i-1][j-1]%m)%m;
    }
    cout << a[k][n] << endl;
}
int main(){
    cin>>k>>n;
    int m=1000000007;
    solve(n, k, m);

    return 0;
}
