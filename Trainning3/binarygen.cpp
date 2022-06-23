#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int BinaryGen(){
    int i;
    int res=0;
    for (i=n-1;i>=0;i--){
        if (s[i]=='0'){
            s[i]='1';
            res=1;
            break;
        }
    }
    for(int j=i+1;j<n;j++) {
            s[j]='0';
    }
    return res;
}
int main(){
    cin>>n;
    cin>>s;
    int res=BinaryGen();
    if (res==1) cout<<s;
    else cout<<-1;

}
