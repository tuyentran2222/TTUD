#include<bits/stdc++.h>
using namespace std;
bool ngoacmo(char x){
    if (x=='{'||x=='['||x=='(') return true;
    return false;
}
bool kiemtra1cap(char x, char y){
    return (x=='('&&y==')')||(x=='['&&y==']')||(x=='{'&&y=='}');
}
int kiemtra(string s){
    stack<char> mt;
    int len=s.size();
    for (int i=0;i<len;i++){
            if (ngoacmo(s[i])){
                     mt.push(s[i]);
            }
            else {
                if (mt.empty()) return 0;
                char m=mt.top();
                mt.pop();
                if (kiemtra1cap(m,s[i])) continue;
                else return 0;
            }
        }
        if (!mt.empty()) return 0;
        return 1;
}
int main(){
    int n=1;
    cin>>n;
    cin.ignore();
    for (int i=1;i<=n;i++){
        string s;
        getline(cin,s);
        int len=s.size();
        cout<<kiemtra(s)<<endl;
    }
}
