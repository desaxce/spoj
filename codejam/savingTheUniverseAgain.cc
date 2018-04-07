/*input
11
1 CS
2 CS
1 SS
6 SCCSSC
2 CC
3 CSCSS
1024 CCCCCCCCCCS
1023 CCCCCCCCCCS
512 CCCCCCCCCCS
511 CCCCCCCCCCS
1 CCCCCCCCCCS
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

string P;

int damage() {
	int f = 1;
	int res = 0;
	forall(i, 0, Size(P)) {
		if (P[i]=='S') {
			res += f;
		} else {
			f = (f << 1);
		}
	}
	return res;
}

void solveCase(int i) {
	printf("Case #%d: ", i+1);

	int D = getNum();
	// P = getLine();
	cin >> P;
	// watch(P);

	int ss = int(count(P.begin(), P.end(), 'S'));
	if (ss > D) {
		printf("IMPOSSIBLE\n");
	} else {
		int h = 0;
		int d = damage();
		// watch(d);
		while (d > D) {
			int i = int(P.rfind("CS")); // We cannot have noend since we checked for IMPOSSIBLE cases
			P[i] = 'S'; P[i+1] = 'C';
			int j = int(count(P.begin(), P.begin() + i, 'C'));
			d -= (1 << j);
			h++;
		}
		printf("%d\n", h);
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