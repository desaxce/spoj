/*input
6 8
1 2
1 4
2 5
3 5
3 6
4 2
5 4
6 6
*/
#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

struct vertex {
	int id;
	int color;
	int pi;
	int d;
	int f;
};

void dfsVisit(vector< vector<int> > adj, int i);

int time = 0;
vector<vertex> vertices;

int main(int argc, char const *argv[])
{
	int V, E;
	scanf("%d %d", &V, &E);

	vector< vector<int> > adj(V);

	for (int i = 0; i < V; ++i)
	{
		vertices.pb({i, 0, -1, 0, 0});

		adj[i] = vector<int>();
	}

	for (int i = 0; i < E; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u-1].pb(v-1);
	}

	// printf("Starting the forest\n");
	for (int i = 0; i < V; ++i)
	{
		if (vertices[i].color == 0) {
			// printf("\tStarting tree from root %d\n", i+1);
			dfsVisit(adj, i);
		}
	}
	return 0;
}

void dfsVisit(vector< vector<int> > adj, int i) {
	vertex *u = &(vertices[i]);
	time+=1;
	u->d = time;
	u->color = 1;

	printf("(%d", i+1);
	// printf("\t\tProcessing vertex n° %d: parent = %d, distance = %d\n", (u->id) + 1, (u->pi) + 1, u->d);

	for (int j = 0; j < adj[i].size(); ++j)
	{
		vertex *v = &(vertices[adj[i][j]]);
		if (v->color == 0) {
			v->pi = i;
			dfsVisit(adj, v->id);
		}
	}

	time += 1;
	u->color = 2;
	u->f = time;
	
	printf(")");
	// printf("\t\tFinish exploration time = %d\n", u->f);
}