/*input
2000
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

const ll MM = 1000000007;
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


// Nombre maximum de variables = N/5 et N <= 2000
ll dp[2001][400];

ll lambda(ll n, ll p) {
	if (dp[n][p] != -1) {
		return dp[n][p];
	}
	dp[n][p] = 0LL;

	if (n > 2) {
		forall(i, 1, (n-2-1)/2+1) {
			dp[n][p] = mod(dp[n][p] + lambda(i, p) * lambda(n-2-i, p), MM);
		}
		dp[n][p] = mod(2LL * dp[n][p], MM);

		if (n%2 == 0) dp[n][p] = mod(dp[n][p]+pow2(lambda(n/2-1, p)), MM);
	}

	if (n >= 6) dp[n][p] = mod(dp[n][p] + lambda(n-5, p+1), MM);

	return dp[n][p];
}

ll bigLambda(ll n) {
	ll resultat = 0;
	forall(i, 0, n+1) {
		resultat = mod(resultat + lambda(i, 0), MM);
	}
	return resultat;
}

ll N;



int main(int argc, char const *argv[])
{
	N = getNum();

	forall(i, 0, N+1) {
		forall(j, 0, 400) {
			dp[i][j] = -1;
		}
	}

	forall(j, 0, 400) {
		dp[0][j] = 0LL; // taille 0
		dp[1][j] = j*1LL; // 1 pour chaque variable disponible
		dp[2][j] = 0LL; // tailles 2 et 3 impossibles
		dp[3][j] = 0LL; // car il faut au moins 2 parenthèses
	}
	
	printf("lambda(%lld) = %lld\n", N, lambda(N, 0));
	printf("LAMBDA(%lld) = %lld\n", N, bigLambda(N));
	return 0;
}