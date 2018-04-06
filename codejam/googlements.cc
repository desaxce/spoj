/*input
4
10
20
1
123
*/
#define LINEBYLINE
#include<bits/stdc++.h>

#define watch(x) 					cout << (#x) << " is " << (x) << endl
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define pb 							push_back
#define mp 							make_pair

using namespace std;

typedef long long ll;

#define Size(x) (int(x.size()))


map<string, ll> ancestors;

string getLine() {
	string s;
	while(!feof(stdin)) {
		char c = fgetc(stdin);
		if(c <= 0) continue;
		if(c == 13) continue;
		if(c == 10) return s;
		s += c;
	}
  	return s;
}

int getNum() {
#ifdef LINEBYLINE
 	string s = getLine();
 	return atoi(s.c_str());
#else
  	int i;
	scanerr = scanf("%d", &i);
 	return i;
#endif
}

int binomialCoeff(int n, int k)
{
    int C[k+1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1;  // nC0 is 1
 
    for (int i = 1; i <= n; i++)
    {
        // Compute next row of pascal triangle using
        // the previous row
        for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j-1];
    }
    return C[k];
}

ll getNbAncestors(vector<int> elmt) {
	string s = "";
	forall(i, 0, Size(elmt)) {
		s += elmt[i] + '0';
	}

	if (ancestors.find(s) != ancestors.end()) {
		return 0; // already counted this ancestor
	}
	ancestors[s] = 1;
	// watch(s);
	if (Size(elmt) == 1) {
		return 1ll;
	}
	int nbDigitsParent = 0;
	int nbDigitsGrandParent = 0;
	forall(i, 0, Size(elmt)) {
		nbDigitsParent += elmt[i];
		nbDigitsGrandParent += elmt[i] * (i+1);
	}
	// watch(nbDigitsParent);
	// watch(nbDigitsGrandParent);
	if (nbDigitsParent > Size(elmt)) {
		return 1; // no ancestors
	}

	if (nbDigitsGrandParent > Size(elmt)) {


		ll res = 1;
		int newSize = Size(elmt);
		forall(i, 0, Size(elmt)) {
			res *= binomialCoeff(newSize, elmt[i]);
			newSize -= elmt[i];
		}
		// watch(1+res);
		return 1+res;
	} else {
		vector<int> parent(Size(elmt)-nbDigitsParent, 0); // We start with some zeroes
		forall(i, 0, Size(elmt)) {
			for (int j = 0; j < elmt[i]; j++) {
				parent.pb(i+1);
			}
		}

		// No real need to sort
		sort(parent.begin(), parent.end());
		ll res = 1;
		
		// string decayed(Size(elmt), '0');
		// decayed[0] = '1';
		// if (s == decayed) {
		// 	res += 1;
		// }
		do {
			res += getNbAncestors(parent);
  		} while (next_permutation(parent.begin(), parent.end()));
  		
  		return res;
	}
}

void solveCase(int i) {
	string G = getLine();
	ancestors.clear();

	vector<int> elmt(Size(G));
	forall(i, 0, Size(G)) {
		elmt[i] = G[i]-'0';
	}
	printf("Case #%d: %Ld\n", i+1, getNbAncestors(elmt));
}

int main(int argc, char const *argv[])
{
	int T = getNum();

	forall(i, 0, T) {
		solveCase(i);
	}
	return 0;
}