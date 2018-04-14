/*input
6
3 6 1 1
.@@..@
.....@
@.@.@@
4 3 1 1
@@@
@.@
@.@
@@@
4 5 1 1
.....
.....
.....
.....
4 4 1 1
..@@
..@@
@@..
@@..
3 4 2 2
@.@@
@@.@
@.@@
3 4 1 2
.@.@
@.@.
.@.@
*/
#include<bits/stdc++.h>

//#define LINEBYLINE

#define pow2(x) 					((x)*(x))
#define	mod(x, m) 					((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) 				max(a, max(b, c))
#define min3(a, b, c) 				min(a, min(b, c))
#define watch(x) 					cout << (#x) << " is " << (x) << endl
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define pb 							push_back
#define mp 							make_pair
#define Size(x) 					(int(x.size()))
#define gcd(a, b)					__gcd((a), (b))
#define count_ones 					__builtin_popcountl

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

const double pi = 2 * acos(0.0);
int oo = 0x3f3f3f3f;

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

int scanerr;

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

int T;

void solveCase(int i) {
	// watch(i);
	printf("Case #%d:", i+1);

	int R = getNum();
	int C = getNum();
	int H = getNum();
	int V = getNum();

	getLine(); // EOL
	vector<int> rows(R, 0);
	vector<int> cols(C, 0);

	vector<string> grid(R);

	int nbChoc = 0;
	forall(j, 0, R) {
		string line = getLine();
		grid[j] = line;
		// watch(line);
		forall(k, 0, C) {
			if (line[k] == '@') {
				rows[j]++;
				cols[k]++;
				nbChoc++;
			}
		}
	}

	// cout << rows[0] << ", " ;
	forall(j, 0, R-1) {
		rows[j+1] += rows[j];
		// cout << rows[j+1] << ", " ;
	}
	forall(j, 0, C-1) {
		cols[j+1] += cols[j];
	}


	vector<int> rowIndices(H+2);
	rowIndices[0] = -1;
	rowIndices[H+1] = R-1;

	vector<int> colIndices(V+2);
	colIndices[0] = -1;
	colIndices[V+1] = C-1;

	if (nbChoc == 0) {
		printf(" POSSIBLE\n");
		return;
	}
	int bits = nbChoc / ((H+1)*(V+1));
	// watch(nbChoc);
	// watch((H+1)*(V+1));
	if (nbChoc % ((H+1)*(V+1)) != 0) {
		printf(" IMPOSSIBLE");
	} else {
		int choc = nbChoc / (H+1);
		forall(j, 1, (H+1) + 1) {
			// cout << j*choc << endl;
			if (find(rows.begin(), rows.end(), j*choc) == rows.end()) {
				// cout << "row " << j << endl;
				printf(" IMPOSSIBLE");
				if (i != T-1) {
					printf("\n");
				}
				return;
			} else {
				forall(k, 0, R+1) {
					if (rows[k] == j*choc) {
						rowIndices[j] = k;
						break;
					}
				}
				// rowIndices[j] = find(rows.begin(), rows.end(), j*choc);
			}
		}
		choc = nbChoc / (V+1);
		forall(j, 1, (V+1)+1) {
			if (find(cols.begin(), cols.end(), j*choc) == cols.end()) {
				// cout << choc * j << endl;
				// cout << "col " << j << endl;
				printf(" IMPOSSIBLE");
				if (i != T-1) {
					printf("\n");
				}
				return;
			} else {
				forall(k, 0, C+1) {
					if (cols[k] == j*choc) {
						colIndices[j] = k;
						break;
					}
				}
				// colIndices[j] = find(cols.begin(), cols.end(), j*choc);
			}
		} 

		forall(j, 0, H) {
			int debutL = rowIndices[j]+1;
			int finL = rowIndices[j+1];
			forall(k, 0, V) {
				int debutC = colIndices[k]+1;
				int finC = colIndices[k+1];
				int cnt = 0;
				forall(n, debutL, finL +1) {
					forall(m, debutC, finC+1) {
						if (grid[n][m] == '@') {
							cnt++;
						}
					}
				}
				if (cnt != bits) {
					printf(" IMPOSSIBLE");
					if (i != T-1) {
						printf("\n");
					}
					return;
				}
			}
		}
		printf(" POSSIBLE");
	}

	if (i != T-1) {
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	T = getNum();

	forall(i, 0, T) {
		solveCase(i);
	}
	return 0;
}