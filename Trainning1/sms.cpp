#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string x;
    cin.ignore();
    string s1=" adgjmptw";
    string s2="behknqux";
    string s3="cfilorvy";
    string s4="sz";
    for (int i=0;i<n;i++){
        getline(cin,x);

        int kq=0;
        int len=x.size();

        for (int j=0;j<len;j++){
            if (s1.find(x[j])<=len) kq++;

            else if (s2.find(x[j])<=len) kq=kq+2;
            else if (s3.find(x[j])<=len) kq=kq+3;
            else if(s4.find(x[j])<=len) kq=kq+4;
        }
        cout<<"Case #"<<i+1<<": "<<kq<<endl;
    }

}
