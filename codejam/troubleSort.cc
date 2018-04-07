/*input
2
5
5 6 8 4 3
3
8 9 7
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

void solveCase(int c) {
	printf("Case #%d: ", c+1);
	int N = getNum();

	vector<int> even((N+1)/2);
	vector<int> odd(N/2);

	// Would scanf be too slow for 10^5 elements?
	forall(i, 0, N) {
		if (i%2 == 0) {
			even[i/2] = getNum();
		} else {
			odd[i/2] = getNum();
		}
	}

	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end());

	vector<int> V(N);
	forall(i, 0, (N+1)/2) {
		V[2*i] = even[i];
	}
	forall(i, 0, N/2) {
		V[2*i+1] = odd[i];
	}

	forall(i, 0, N-1) {
		if (V[i] > V[i+1]) {
			printf("%d", i);
			if (c != T-1) {
				printf("\n");
			}
			return;
		}
	}
	printf("OK");
	if (c != T-1) {
		printf("\n");
	}
}


int main(int argc, char const *argv[])
{
	T = getNum();

	forall(i, 0, T) {
		solveCase(i);
	}

	// srand(time(NULL));
	// printf("100\n");
	// forall(j, 0, 100) {
	// 	int N = rand()%10 + 1;
	// 	printf("%d\n", N);
	// 	forall(i, 0, N) {
	// 		printf("%d", (rand()%100)+1);
	// 		if (i != N-1) {
	// 			printf(" ");
	// 		} else {
	// 			printf("\n");
	// 		}
	// 	}
	// }
	return 0;
}