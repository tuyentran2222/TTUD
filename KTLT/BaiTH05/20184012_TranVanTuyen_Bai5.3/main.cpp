#include <iostream>
using namespace std;
#include <string.h>
#include <stack>

int par(string str){
    int a = str.length();
    stack<char> S;
    char x, y;
    for (int i=0; i<a; i++){
        x = str[i];
        if (x == '(' || x == '[' || x == '{'){
            S.push(x);
        }
        else {
            if (x == ')') {
                if (S.top() == '('){
                    S.pop();
                }
                else return 0;
            }
            else if (x == ']') {
                if (S.top() == '['){
                    S.pop();
                }
                else return 0;
            }
            else if (x == '}') {
                if (S.top() == '{'){
                    S.pop();
                }
                else return 0;
            }
        }
    }
    if (S.empty()){
        return 1;
    }
    else return 0;
}

int main(){
    int n;
    string str;
    cout<<"Ho va ten: Tran Van Tuyen"<<endl;
    cout<<"MSSV: 20184012"<<endl;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        cout << par(str) << endl;
    }

    return 0;
}
