
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
#define X first
#define Y second
typedef long long ll;
vector<iii> edge;
int n, m;

int par[100005];
int anc(int p) {
    if (par[p] == p)
        return p;
    else
        return par[p] = anc(par[p]);
}
void join(int p, int q) { par[anc(p)] = anc(q); }


main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        par[i] = i;
    while (m--) {
        int p, q, w;
        scanf("%d%d%d", &p, &q, &w);
        edge.push_back(iii(w, ii(p, q)));
    }
    sort(edge.begin(), edge.end());
    vector<iii>::iterator it;
    ll  r = 0;
    for (it = edge.begin(); it != edge.end(); it++) {
        if (anc(it->Y.X) != anc(it->Y.Y)) {
            join(it->Y.X, it->Y.Y);
            r += (ll) it->X;
        }
    }
    cout<<r;
}
