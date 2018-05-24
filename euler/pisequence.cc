/*input
100000000
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

vector<int> primes;

// Adds all prime numbers smaller than n to primes
int SieveOfSundaram(int n)
{
	int MAX = n+1;
	bool* a;
    a = (bool*)malloc(MAX * sizeof(bool));
    memset(a, true, MAX);
    unsigned long int i = 1;
    while (i < MAX){

        while (((++i)<MAX)&&(!a[i]));

        if (2 * i >= MAX)
            break;

        for (unsigned long int k = 2 * i; k < MAX; k += i)
            if (a[k])
                a[k] = false;
    }
    // std::cout << "done\n";
    for (unsigned long int i = 2; i < MAX; i++)
        if (a[i])
        	primes.pb(i);
            // std::cout << i << "\n";
    // getchar(); getchar();
}

void solveCase(ll N) {
	// SieveOfSundaram(N); // On se récupère la liste des nombres premiers < N

	printf("Computed primes\n");

	map<ll, map<ll, ll> > d;
	d[1] = map<ll, ll>(); // Vide
	d[2][1] = 1; // (2, 1) est la seule pi-suite.

	for (ll i = 1; i < Size(primes); i++) { // On est déjà passé par 2
		// En fait on a i+1 = pi(primes[i])
		ll j = primes[i];
		ll ppj = i+1;
		// cout << "Processing prime " << j << " with pi("<< j<< ") = " << ppj<< endl;

		// cout << "\tThe map contains the following keys: ";
		// for (map<ll, map<ll, ll> >::iterator it = d.begin(); it!=d.end(); ++it) {
		// 	cout << it->first << "\t";
		// }
		// cout << endl;
		map<ll, map<ll, ll> >::iterator it = d.upper_bound(ppj);
		it--;
		ll p = it->first; 
		// cout << "\tWe have p = " << p << endl;
		if (p == ppj) {// le nbre de nombre premiers <=j est premier!
			// cout << "\tWe are prime!" << endl;
			d[j][0]++; // c'est la pi-suite (j, ppj) avec j et ppj premiers!
			for (map<ll, ll>::iterator it = d[p].begin(); it!=d[p].end(); ++it) {
				d[j][it->first] += it->second;
			}
		} else {
			// cout << "\tNot prime!" << endl;
			// cout << "\tAnd we have " << Size(d[p]) << " elements at level " << p << endl;
			for (map<ll, ll>::iterator it = d[p].begin(); it!=d[p].end(); ++it) {
				d[j][(it->first)+1] += (it->second); // ce sont les pi-suites (j, ppj, ...) avec ppj != p et donc non premier
			}
			d[j][1]++; // correspond à (j, ppj) avec j premier mais ppj non premier
		}
	}

	// for (map<ll, map<ll, ll> >::iterator it = d.begin(); it != d.end(); ++it) {
	// 	cout << it->first << " ::";
	// 	for (map<ll, ll>::iterator it1 = (it->second).begin(); it1!= (it->second).end(); ++it1) {
	// 		cout << " (" << it1->first << ", " << it1->second << ")";
	// 	}
	// 	cout << endl;
	// }

	map<ll, ll> dd;

	for (ll i = 2; i <= N; i++) {
		map<ll, map<ll, ll> >::iterator it1 = d.upper_bound(i);
		it1--;
		ll j = it1->first; 

		if (j == i) {// i est premier
			for (map<ll, ll>::iterator it = d[j].begin(); it!=d[j].end(); ++it) {
				dd[it->first] += it->second;
			}
		} else {
			for (map<ll, ll>::iterator it = d[j].begin(); it!=d[j].end(); ++it) {
				dd[(it->first)+1] += it->second;
			}
		}
	}

	ll resultat = 1;
	for (map<ll, ll>::iterator it = dd.begin(); it!=dd.end(); ++it) {
		// cout << it->first << " :: " << it->second << endl;
		resultat = mod(resultat * (it->second), 1000000007);
	}

	cout << resultat << endl;

}

int main(int argc, char const *argv[])
{
	ll N = getNum();
	SieveOfSundaram(N);
	cout << Size(primes) << endl;
	solveCase(N);
	return 0;
}