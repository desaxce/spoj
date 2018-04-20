/*input
2
9 10
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 19
2 10
1 2
1 2
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
	printf("Case #%d:", i+1);
	int N = getNum();
	int W = getNum();

	vector<int> weights(N);
	vector<int> values(N);

	forall(i, 0, N) {
		int temp = getNum();
		weights[i] = temp;
	}
	forall(i, 0, N) {
		int temp = getNum();
		values[i] = temp;
	}

	vector<int> m(W+1, 0);
	m[0] = 0;

	forall(w, 1, W+1) {
		forall(j, 0, N) {
			if (w >= weights[j]) {
				int value = m[w-weights[j]];
				if (values[j] + value > m[w]) {
					m[w] = values[j] + value;
				}
			}
		}
	}
	printf(" %d", m[W]);
	if (i != T-1) {
		printf("\n");
	}

}

int main(int argc, char const *argv[])
{
	int T = getNum();

	forall(i, 0, T) {
		solveCase(i);
	}
	return 0;
}