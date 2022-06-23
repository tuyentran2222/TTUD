#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
/*
 b1: Tim vi tri lon nhat A(k))<A(k+1) neu khong tim duoc dung thuat toan
 b2: Tim vi tri L lon nhat thoa man A(k)<A(L)
 b3: Doi cho A(K) va A(L)
 b4: dao nguoc mang trong doan A(k+1)...A(n)
 */
 void print() {
    for (int i=0; i<a.size(); i++) cout << a[i] << " ";
    cout << endl;
}

int  permute() {
        int res=0;
        int k, l;
        for (k = n-2; k>=0; k--) if (a[k] < a[k+1]) break; // 1
        if (k<0) return res;                                    //
        for (l = n-1; l>k; l--) if (a[k] < a[l]) break; // 2
        swap(a[k], a[l]);
        for (int i=k+1, j=n-1; i<j; i++, j--) swap(a[i], a[j]); // 4
        return 1;
}

int main() {
    cin>>n;
    int x;
    for (int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    int res=permute();
    if (res==0) cout<<-1;
    else print();
    return 0;
}
