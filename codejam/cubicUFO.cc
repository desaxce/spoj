/*input
2
1.000000
1.414213
*/
#include<bits/stdc++.h>

#define LINEBYLINE

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
	printf("Case #%d:\n", i+1);
	double A = stod(getLine());

	double theta = pi/4. - acos(A/sqrt(2.));
	// watch(A);
	// watch(theta);

	printf("%.8f %.8f %.8f\n", cos(theta)/2., sin(theta)/2., 0.0);
	printf("%.8f %.8f %.8f\n", -sin(theta)/2., cos(theta)/2., 0.0);
	printf("%.8f %.8f %.8f", 0.0, 0.0, 0.5);
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