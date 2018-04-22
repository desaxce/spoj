/*input
1
10000 4
2
4000 400
3000 250
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

vector<int> m;

void solveCase(int i) {
	// printf("Case #%d:", i+1);

	int K = getNum();
	int Y = getNum();

	int d = getNum();

	vector<int> v(d);
	vector<int> w(d);

	forall(j, 0, d) {
		int weight = getNum();
		int value = getNum();
		v[j] = value;
		w[j] = weight;
		// cout << weight << ", " << value << endl;
	}
	int y = 0;
	int oldK = K;
	while (y < Y) {
		// watch(y);
		K = oldK/1000;
		m = vector<int>(K+1, 0);

		forall(k, 1, K+1) {
			forall(j, 0, d) {
				if (k*1000 >= w[j]) {
					m[k] = max(m[k], m[(k*1000-w[j])/1000]+v[j]);
				}
			}
		}
		oldK = oldK + m[K];
		// watch(oldK);

		y++;
	}

	printf("%d", oldK);
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