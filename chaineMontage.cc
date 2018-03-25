/*input
6
2 3
7 9 3 4 8 4
2 3 1 3 4
4 2
8 5 6 4 5 7
2 1 2 2 1
*/
#define pb push_back
#include <iostream>
#include <vector>
using namespace std;


int nbPostes;

int e1, s1; // coûts entrée/sortie chaîne 1
vector<int> p1; // postes chaîne 1
vector<int> t1; // transitions chaîne 1

int e2, s2; // coûts entrée/sortie chaîne 2
vector<int> p2; // postes chaîne 2
vector<int> t2; // transitions chaîne 2

void parse();
void afficherPostes(int j, int l, vector<int> l1, vector<int> l2);
// First line: nombre de postes
// Then come 3 lines for each chaîne de montage:
// - coûts d'entrée et de sortie
// - coûts de chaque poste
// - coûts de transition d'une chaîne à l'autre
int main(int argc, char const *argv[])
{
	parse();

	vector<int> f1;
	vector<int> f2;
	vector<int> l1;
	vector<int> l2;

	f1.pb(e1+p1[0]);
	f2.pb(e2+p2[0]);
	for (int i = 1; i < nbPostes; ++i)
	{
		if (f1[i-1] <= f2[i-1] + t2[i-1]) {
			f1.pb(f1[i-1] + p1[i]);
			l1.pb(1);
		} else { // case where going with the transition is faster
			f1.pb(f2[i-1] + t2[i-1] + p1[i]);
			l1.pb(2);
		}

		if (f2[i-1] <= f1[i-1] + t1[i-1]) {
			f2.pb(f2[i-1] + p2[i]);
			l2.pb(2);
		} else {
			f2.pb(f1[i-1] + t1[i-1] + p2[i]);
			l2.pb(1);
		}
	}

	int f, l;

	if (f1[nbPostes-1] + s1 <= f2[nbPostes-1] + s2) {
		f = f1[nbPostes-1] + s1;
		l = 1;
	} else {
		f = f2[nbPostes-1] + s2;
		l = 2;
	}

	afficherPostes(nbPostes-1, l, l1, l2);
	return 0;
}

void afficherPostes(int j, int l, vector<int> l1, vector<int> l2) {
	if (j == -1) {
		return;
	}

	int ll = l;
	if (ll == 1) {
		ll = l1[j];
	} else {
		ll = l2[j];
	}
	afficherPostes(j-1, ll, l1, l2);
	if (j == nbPostes-1) {
		printf("Chaîne %d, poste %d\n", l, j+1); // Pour l'affichage on affiche les postes 1-based
	} else {
		printf("Chaîne %d, poste %d\n", ll, j+1); // Pour l'affichage on affiche les postes 1-based
	}
}

void parse() {
	scanf("%d", &nbPostes);

	scanf("%d %d", &e1, &s1);

	for (int i = 0; i < nbPostes; ++i)
	{
		int cost;
		scanf("%d", &cost);
		p1.push_back(cost);
	}

	for (int i = 0; i < nbPostes-1; ++i)
	{
		int cost;
		scanf("%d", &cost);
		t1.push_back(cost);
	}

	scanf("%d %d", &e2, &s2);

	for (int i = 0; i < nbPostes; ++i)
	{
		int cost;
		scanf("%d", &cost);
		p2.push_back(cost);
	}

	for (int i = 0; i < nbPostes-1; ++i)
	{
		int cost;
		scanf("%d", &cost);
		t2.push_back(cost);
	}
}