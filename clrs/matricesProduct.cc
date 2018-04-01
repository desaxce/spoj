/*input
6
30 35 15 5 10 20 25
*/
#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

void afficherParentheses(vector< vector<int> > s, int i, int j);

// Trouve l'agencement de parenthèses optimal pour minimiser
// le nombre d'opérations élémentaires
int main(int argc, char const *argv[])
{
	int n; // nombre de matrices
	scanf("%d", &n);

	vector<int> p(n+1);

	for (int i = 0; i < n+1; ++i)
	{
		int temp;
		scanf("%d", &temp);
		p[i] = temp;
	}

	vector< vector<int> > s(n);
	for (int i = 0; i < n; ++i)
	{
		s[i] = vector<int>(n);
	}

	int** m = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		m[i] = new int[n];
	}

	// Same index ==> no multiplication when l = 1
	for (int i = 0; i < n; ++i)
	{
		m[i][i] = 0;
	}

	for (int l = 2; l <= n; ++l) // l = longueur chaîne
	{
		for (int i = 0; i < n-l+1; ++i)
		{
			int j = i+l-1; // de i à j on a une chaîne de longueur l
			m[i][j] = -1;
			for (int k = i; k < j; k++) { // interdit d'avoir k = j
				int q = m[i][k]+m[k+1][j] + p[i]*p[k+1]*p[j+1];
				if (m[i][j] == -1 or q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}

	// Unallocate m
	for (int i = 0; i < n; ++i)
	{
		delete [] m[i];
	}
	delete [] m;

	afficherParentheses(s, 0, n-1);
	return 0;
}

void afficherParentheses(vector< vector<int> > s, int i, int j) {
	if (i == j) {
		printf("A%d", i+1);
	} else {
		printf("(");
		afficherParentheses(s, i, s[i][j]);
		afficherParentheses(s, s[i][j]+1, j);
		printf(")");
	}
}