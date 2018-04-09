/*input
9 14
1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 9 2
3 6 4
4 5 9
4 6 14
5 6 10
6 7 2
7 8 1
7 9 6
8 9 7
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
	int src;
	int dest;
	int poids;

	bool operator<(const Edge& e) {
		return this->poids < e.poids;
	}
};

struct Graph {
	int S, A;

	Edge* edges;
};

struct subset {
	int parent;
	int rank;
};

struct Graph* createGraph(int S, int A) {
	Graph* graph = (Graph*) malloc(sizeof(Graph));
	graph->S = S;
	graph->A = A;

	graph->edges = (Edge*) malloc(A * sizeof(Edge));
	return graph;
}

// Search for representatives and update subset
int find(subset subsets[], int i) {
	if (subsets[i].parent != i) {
		return subsets[i].parent = find(subsets, subsets[i].parent);
	}
	return subsets[i].parent;
}

void Union(subset subsets[], int x, int y) {
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (subsets[xroot].rank < subsets[yroot].rank) {
		subsets[xroot].parent = yroot;
	} else if (subsets[xroot].rank > subsets[yroot].rank) {
		subsets[yroot].parent = xroot;
	} else {
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

Graph* msa(Graph* g) {
	int S = g->S;
	int A = g->A;

	Graph* T = createGraph(g->S, g->A);

	Edge* edges = g->edges;
	sort(edges, edges+A);

	// for (int i = 0; i < A; i++) {
	// 	printf("%d %d: %d \n", edges[i].src, edges[i].dest, edges[i].poids);
	// }
	subset* subsets = (subset*) malloc(S * sizeof(subset));

	for (int v = 0; v < S; v++) {
		subsets[v] = {v, 0};
	}

	int cnt = 0;
	for (int e = 0; e < A; e++) {
		int xroot = find(subsets, edges[e].src-1);
		int yroot = find(subsets, edges[e].dest-1);

		if (xroot == yroot) continue;

		Union(subsets, edges[e].src-1, edges[e].dest-1);
		T->edges[cnt] = {edges[e].src, edges[e].dest, edges[e].poids};
		cnt++;
	}
	T->A = cnt; // Not a very nice way to finish
	return T;
}

int main(int argc, char const *argv[])
{
	int S, A;
	scanf("%d %d", &S, &A);
	// cout << S << " " << A << endl;
	Graph* g = createGraph(S, A);

	for (int i = 0; i < A; i++) {
		int src, dest, poids;
		scanf("%d %d %d", &src, &dest, &poids);
		g->edges[i] = {src, dest, poids};
		// printf("%d %d: %d \n", g->edges[i].src, g->edges[i].dest, g->edges[i].poids);
	}

	Graph* T = msa(g);
	
	Edge* edges = T->edges;

	int poids = 0;
	for (int e = 0; e < T->A; e++) {
		printf("Edge from %c to %c, poids = %d\n", edges[e].src+'a'-1, edges[e].dest+'a'-1, edges[e].poids);
		poids += edges[e].poids;
	}

	printf("Poids total = %d\n", poids);
	return 0;
}