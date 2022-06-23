#include<bits/stdc++.h>
using namespace std;
int main(){
    string str,str1,str2,str3;
    str1="ha Noi trong toi la mot cai gi do";
    str2="la mot ";
    str3="ky uc buon. ";
    str.append(str1);
    str.append(str2);
    str.append(str3);
    str.append(str1,0,6);
    str.append (10u,'.');

    cout<<str<<endl;
    for (int i=0;i<str.length();i++){
        cout<<str.at(i)<<" ";
    }

    str.back()='!';
    cout<<str<<endl;
    cout<<"size: "<<str.size()<<endl;
    cout<<"length: "<<str.length()<<endl;
    cout<<"capacity: "<<str.capacity()<<endl;
    cout<<"max_size: "<<str.max_size()<<endl;
    string resultCompare;
    if (str1.compare(str2)>0){
        resultCompare=str1+"lon hon "+str2   ;
    }
    else if (str1.compare(str2)<0){
        resultCompare=str2+"lon hon "+str1 ;
    }
    else resultCompare="Hai xau bang nhau";
    cout<<"compare: "<<resultCompare<<endl;

    cout<<"find pos first:"<<str.find("dola")<<endl;
    cout<<"find pos last: "<<str.find_last_of("la")<<endl;




}
