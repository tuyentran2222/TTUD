
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int oo = 0x3c3c3c3c;
//Thuat toan Tarjan
//https://vi.wikipedia.org/wiki/Thu%E1%BA%ADt_to%C3%A1n_t%C3%ACm_th%C3%A0nh_ph%E1%BA%A7n_li%C3%AAn_th%C3%B4ng_m%E1%BA%A1nh_c%E1%BB%A7a_Tarjan
int n, m, Num[N], Low[N], cnt = 0;
vector<int> a[N];
stack<int> st;
int Count = 0;
void input(){
    cin>>n>>m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin>>x>>y;
        a[x].push_back(y);
    }
}
void visit(int u) {
    Low[u] = Num[u] = ++cnt;
    st.push(u);

    for (int v : a[u])
        if (Num[v])
            Low[u] = min(Low[u], Num[v]);
        else {
            visit(v);
            Low[u] = min(Low[u], Low[v]);
        }

    if (Num[u] == Low[u]) {  // found one
        Count++;
        int v;
        do {
            v = st.top();
            st.pop();
            Num[v] = Low[v] = oo;  // remove v from graph
        } while (v != u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    for (int i = 1; i <= n; i++)
        if (!Num[i]) visit(i);

    cout << Count << endl;
}
