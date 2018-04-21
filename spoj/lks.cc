/*input
10 3
7 3
8 8
4 6
*/
#include<bits/stdc++.h>

// #define LINEBYLINE

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
	// printf("Case #%d:", i+1);

	int K = getNum(); // max weight
	int N = getNum(); // nb of items

	vector<int> v(N); // values
	vector<int> w(N); // weights

	forall(j, 0, N) {
		int value = getNum();
		int weight = getNum();
		v[j] = value;
		w[j] = weight;
	}

	vector<int> m(K+1, 0);

	forall(j, 0, N) {
		for (int k = K; k>=w[j]; k--) {
			m[k] = max(m[k], v[j]+m[k-w[j]]);
		}
	}

	printf("%d", m[K]);
	// vector< vector<int> > m(N+1);
	// forall(j, 0, N+1) {
	// 	m[j] = vector<int>(K+1);
	// }
	// forall(k, 0, K+1) {
	// 	m[0][k] = 0;
	// }


	// forall(j, 1, N+1) {
	// 	forall(k, 0, K+1) {
	// 		if (k >= w[j-1]) { // we have to offset the indices of w and v by 1
	// 			m[j][k] = max(m[j-1][k], v[j-1] + m[j-1][k-w[j-1]]);
	// 		} else {
	// 			m[j][k] = m[j-1][k];
	// 		}
	// 	}
	// }
	// printf(" %d\n", m[N][K]);
	if (i != T-1) {
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	// T = getNum();
	T = 1;

	forall(i, 0, T) {
		solveCase(i);
	}
	return 0;
}	