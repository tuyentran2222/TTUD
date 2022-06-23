#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long a,b,sd1,sd2;
    cin>>a>>b;
    unsigned long long kq= pow(10,9)+7;
    sd1=a%kq;
    sd2=b%kq;
    cout<< (sd1+sd2)%kq;
    return 0;
}
