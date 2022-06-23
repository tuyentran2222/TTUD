#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
int a[MAX];
int n;
int S0[MAX];// tong chan
int S1[MAX];// tong le
bool solved0[MAX];//  solved0[i] = true neu tong chan S0[i] ton tai
bool solved1[MAX];// solved1[i] = true neu tong le S1[i] ton tai


void input(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

}
void solve(){
    int ans;
    if(a[1]%2 == 0){
        S0[1] = a[1]; solved0[1] = true; solved1[1] = false;
    }else{
        S1[1] = a[1]; solved0[1] = false; solved1[1] = true;
    }

    for(int i = 2; i <= n; i++){
        if(a[i]%2 == 0){// a[i] chan
            if(solved0[i-1]){
                S0[i] = max(a[i],a[i] + S0[i-1]);
            }else{
                S0[i] = a[i];
            }
            solved0[i] = true;

            if(solved1[i-1]){
                S1[i] = S1[i-1] + a[i]; solved1[i] = true;
            }else{
                solved1[i] = false;
            }
        }else{// a[i] le
            if(solved1[i-1]){
                    S0[i] = S1[i-1] + a[i]; solved0[i] = true;
            }else{
                solved0[i] = false;
            }
            if(solved0[i-1]){
                S1[i] = max(a[i], a[i] + S0[i-1]);
            }else{
                S1[i] = a[i];
            }
            solved1[i] = true;
        }
    }
    bool notfound = true;

    for(int i = 1; i <= n; i++){
        if(solved0[i]){
            if(notfound) {
                ans = S0[i];
                notfound = false;
            }else{
                if(ans < S0[i]) {
                    ans = S0[i];
                }
            }
        }
    }
    if(notfound) cout << "NOT_FOUND";
    else
    cout << ans;

}

int main(){
    input();
    solve();
}
