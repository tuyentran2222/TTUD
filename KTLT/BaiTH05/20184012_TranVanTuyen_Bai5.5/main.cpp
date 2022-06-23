#include <bits/stdc++.h>
using namespace std;
bool namNhuan(int year){
    if ((year%4==0&& year%100!=0)||(year%400==0)) return true;
    return false;
}

int main(){
    cout<<"Ho va ten: Tran Van Tuyen"<<endl;
    cout<<"MSSV: 20184012"<<endl;
    int n;
    cin >> n;
    int a[n];
    bool found = false;
    for (int i=0;i<n;i++){
        cin>>a[i];
        if (namNhuan(a[i])) {found=true;break;}
    }
    if (found) cout << "Yes";
    else cout << "No";
    return 0;
}
