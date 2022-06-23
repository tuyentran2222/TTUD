
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
int N;//number of nodes
int M;//number of edges
typedef pair<int, int> iPair;
vector<iPair> adj[100005];
// To add an edge
void addEdge( int u,int v, int wt)
{
	adj[u].push_back(make_pair(v, wt));
	//adj[v].push_back(make_pair(u, wt));
}

void shortestPath(int src,int des)
{
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
	vector<int> dist(N+1, INT_MAX);
	pq.push(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		for (auto x : adj[u]){

			int v = x.first;
			int weight = x.second;.
			if (dist[v] > dist[u] + weight)
			{
				// Updating distance of v
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));

			}
		}
	}
    if (dist[des]==INT_MAX) cout<<-1;
	else cout<<dist[des];
}

// Driver program to test methods of graph class
int main()
{
    cin>>N>>M;
	int a,b,c;
	for (int i=1;i<=M;i++){
        cin>>a>>b>>c;
        addEdge(a,b,c);
	}

    int s,t;
    cin>>s>>t;
	shortestPath(s,t);

	return 0;
}
