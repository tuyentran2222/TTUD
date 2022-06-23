#include <bits/stdc++.h>
using namespace std;
int a[5];
void cal(double a1){
    if (a1 < 4) a[0]++;
    if (4 <= a1 && a1 < 5.5) a[1]++;
    if (5.5 <= a1 && a1 < 7) a[2]++;
    if (7 <= a1 && a1 < 8.5) a[3]++;
    if (8.5 <= a1) a[4]++;
}

int main(){
    cout<<"Ho va ten: Tran Van Tuyen"<<endl;
    cout<<"MSSV: 20184012"<<endl;
    int n;
    cin >> n;
    while(n--){
        int b;
        cin >> b;
        cal(b);
    }

    cout << a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3];
}
