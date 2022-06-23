#include <iostream>
#include <bits/stdc++.h>
#include<string.h>

using namespace std;

int main()
{
    unsigned long long a,b,a1,b1;
    int sd1,sd2,c1,c2;
    cin>>a>>b;
    a1=a/10;
    b1=b/10;
    sd1= a%10;
    sd2=b%10;
    c1=(sd1+sd2)/10;
    c2=(sd1+sd2)%10;
    if (a1+b1+c1>0){
        cout<< a1+b1+c1<<c2;
    }
    else cout<< c2<<endl;



    return 0;
}
