#include<deque>
#include<bits/stdc++.h>
using namespace std;
int main(){
    deque<string> myDeque;
    cout<< myDeque.size()<<endl;
    for (int i=0;i<=5;i++){
        string str2="abc";
        string str;
        str.append(str2);
        str.append(to_string(i));
        myDeque.push_back(str);
    }
    deque<string>::iterator it=myDeque.begin();
    int d=1;
    while(it!=myDeque.end()){
        cout<<"Phan tu thu "<<d<<":"<<*it++<<endl;
        d++;
    }
    cout<<"front: "<<myDeque.front()<<endl;
    cout<<"back:  "<<myDeque.back()<<endl;
    myDeque.pop_front();
    d=1;
    it=myDeque.begin();
    while(it!=myDeque.end()){
        cout<<"Phan tu thu "<<d<<":"<<*it++<<endl;
        d++;
    }

    cout<<myDeque.size()<<endl;


}
