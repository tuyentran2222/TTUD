#include <bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Ho va ten: Tran Van Tuyen"<<endl;
    cout<<"MSSV: 20184012"<<endl;
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    while(n--){
        int k, t;
        cin >> k >> t;
        while(k--){
            int a;
            cin >> a;
            if (t == 1) sum += a;
            if (t == -1) sum -= a;
            ans = max(ans, -sum);
        }
    }
    cout << ans;
}
