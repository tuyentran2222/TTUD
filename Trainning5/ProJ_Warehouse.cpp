#include <bits/stdc++.h>
using namespace std;

#define MAX 1005
int n, T, d;
int a[MAX];
int t[MAX];
int L[MAX][MAX];//L[i][j] luong hang lon nhat voi dia diem cuoi i thoi gian j
int res = 0;

void input() {
    cin >> n >> T >> d;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> t[i];
}

void solve(){
    for(int i = 1; i <= n; i++)
        for(int k = t[i]; k <= T; k++) {
            int m=i-d;
            if (i-d<=0) m=0;
            for(int j = i-1; j >=m; j--)
                L[i][k] = max(L[i][k], L[j][k-t[i]] + a[i]);
            res = max(res, L[i][k]);
        }
    cout << res;
}

int main() {
    input();
    solve();
    return 0;
}
