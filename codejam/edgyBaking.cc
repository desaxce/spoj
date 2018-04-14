/*input
3
1 7
1 1
2 920
50 120
50 120
1 32
7 4
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

struct Rectangle {
	int W;
	int H;
	double diag;
};

int T;

void solveCase(int i) {
	printf("Case #%d:", i+1);

	int N = getNum();
	int P = getNum();

	vector<Rectangle> cookies(N);

	forall(j, 0, N) {
		int W = getNum();
		int H = getNum();
		cookies[j] = {W, H, sqrt(pow2(W)+pow2(H))};
	}

	Rectangle r = cookies[0];

	int delta = P - 2*N*(r.W+r.H);
	double finalValue = 0;

	int wh = r.W;

	if (delta < wh) {
		finalValue =  max(finalValue, 1.0*P-delta);
	} else if (delta > 2.*r.diag * N) {
		finalValue =  max(finalValue, 2.*N*(r.W+r.H+r.diag));
	} else {
		double nbRectangles = floor(1.0*delta/wh);
		double maxValue = 2*nbRectangles * r.diag;
		if (maxValue > delta) {
			finalValue =  max(finalValue, 1.0*P);
		} else {
			finalValue = max(finalValue, maxValue+2.*N*(r.W+r.H));
		}
	}
	wh = r.H;

	if (delta < wh) {
		finalValue =  max(finalValue, 1.0*P-delta);
	} else if (delta > 2.*r.diag * N) {
		finalValue =  max(finalValue, 2.*N*(r.W+r.H+r.diag));
	} else {
		double nbRectangles = floor(1.0*delta/wh);
		double maxValue = 2*nbRectangles * r.diag;
		if (maxValue > delta) {
			finalValue =  max(finalValue, 1.0*P);
		} else {
			finalValue = max(finalValue, maxValue+2.*N*(r.W+r.H));
		}
	}
	printf(" %.8f", finalValue);
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