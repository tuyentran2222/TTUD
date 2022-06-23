#include <bits/stdc++.h>
using namespace std;

int n,k;
int res[10005];
int giaithua(int i){
    if (i==0||i==1) return 1;
    return i*giaithua(i-1);
}

vector<int> myvector;
int main(){
    cin>>n>>k;
    for (int i=0;i<n;i++){
        myvector.push_back(i+1);
    }

    int i=0;
    if (n<=13){
        if (k>=giaithua(n)){
            cout<<-1;
            return 0;
        }
    }
    if (n>13){
        for (i=0;i<n-13;i++){
            res[i]=i+1;
            myvector.erase(myvector.begin());
        }

    }
    int index=k;
    int begin1;
    if (n>13) begin1=i;
    else begin1=0;
    int indexI=k;
    k--;
    int soluong=(n>13)?(n-i):n;
    while (i!=n){
        index=k/giaithua(soluong-1);
        res[begin1]=myvector[index];
        k=k%giaithua(soluong-1);
        soluong--;
        i++;
        begin1++;
        myvector.erase(myvector.begin()+index);
        //cout<<"index="<<index<<"res=" <<res[begin1]<<"k="<<k <<endl;
    }
    for (int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }


}
