#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int L0[1000005];//do dai day con tang ket thuc boi  duong
int L1[1000005];//am

int best=1;
int solve(){
    L0[0]=0;
    L1[0]=0;
    for (int i=1;i<=n;i++){
        if (a[i]>0){
            L0[i]=1;
            for (int j=1;j<=i-1;j++){
                if (a[j]<0){
                    if (abs(a[j])<a[i]){
                    L0[i]=max(L1[j]+1,L0[i]);
                    }
                }
            }

        }
        if (a[i]<0){
            L1[i]=1;
            for (int j=1;j<=i-1;j++){
                if (a[j]>0){
                    if (abs(a[j])<abs(a[i])){
                        L1[i]=max(L0[j]+1,L1[i]);
                    }
                }

            }
        }
        if (a[i]==0){
            continue;
        }
    }
    for (int i=1;i<=n;i++){
        best=max(best,L0[i]);
        best=max(best,L1[i]);
    }

    return best;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<solve();


    return 0;
}
