/*input
8 9 2
1 2
1 5
2 6
6 3
6 7
3 4
3 7
7 4
7 8
4 8
*/
#include <iostream>
#include <vector>
#include <deque>
#define pb push_back
using namespace  std;

int main(int argc, char const *argv[])
{
	int v, e, s;
	scanf("%d %d %d", &v, &e, &s);

	s-=1;

	vector< vector<int> > adj(v);
	for (int i = 0; i < v; ++i)
	{
		adj[i] = vector<int>(0);
	}

	for (int i = 0; i < e; ++i)
	{
		int u, w;
		scanf("%d %d", &u, &w);
		adj[u-1].pb(w-1);
		adj[w-1].pb(u-1);
	}

	vector<int> color(v, 0);
	vector<int> d(v, -1);
	vector<int> pi(v, -1);

	color[s] = 1;
	d[s] = 0;
	pi[s] = -1;

	deque<int> F(0);
	F.pb(s);

	while (!F.empty()) {
		int u = F.front();
		printf("Processing vertex n° %d: parent = %d and distance = %d\n", u+1, pi[u]+1, d[u]);
		for (int i = 0; i < adj[u].size(); ++i)
		{
			int w = adj[u][i];
			if (color[w] == 0) {
				color[w] = 1;
				d[w] = d[u] + 1;
				pi[w] = u;
				F.pb(w);
			}
		}
		F.pop_front();
		color[u] = 2; // not really needed;
	}

	return 0;
}