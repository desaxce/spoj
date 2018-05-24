/*input
60
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

ll nbShuffles(ll n) {
	ll u = 0;
	ll p2 = 1;
	ll cnt = 0;
	do {
		u = mod(u+p2, n-1);
		p2 = mod(2*p2, n-1);
		cnt++;
	} while (u!= 0 && cnt < 65);
	if (cnt == 65) return -1;
	return cnt;
}

bool isNbShuffles(int n, int k) {
	ll p2 = 1;
	for (int i = 0; i < k; i++) {
		p2 = mod(p2*2, n-1);
	}
	int uk = mod(p2-1, n-1);
	
	if (uk != 0) return false;

	return nbShuffles(n) == k;
}

vector<ll> getDivisors(ll primes[], ll orders[]) {
	vector<ll> result;
	result.pb(1ll);

	for (ll i = 0; i < 11; i++) {
		ll p = primes[i];
		ll alpha = orders[i];
		
		ll pj = p;
		vector<ll> temp;
		for (ll j = 0; j < alpha; j++) {
			for (ll d : result) {
				temp.pb(d*pj);
			}
			pj *= p;
		}
		result.insert(result.end(), temp.begin(), temp.end());
	}
	return result;
}

ll N;

int main(int argc, char const *argv[])
{
	N = getNum();
	ll result = 0;

	ll primes[11] = {3, 5, 7, 11, 13, 31, 41, 61, 151, 331, 1321};
	ll orders[11] = {2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	vector<ll> divisors = getDivisors(primes, orders);

	cout << Size(divisors) << endl;
	// for (ll d : divisors) {
	// 	cout << d << endl;
	// }

	// vector<ll> divisors;
	// divisors.pb(1);
	// divisors.pb(3);
	// divisors.pb(5);
	// divisors.pb(15);
	// divisors.pb(17);
	// divisors.pb(51);
	// divisors.pb(85);
	// divisors.pb(255);

	for (ll d : divisors) {
		bool isCorrect = true;
		ll p2 = 1;
		for (int i = 1; i <= N-1; i++) {
			p2 *= 2;
			if ((p2-1) % d == 0) {
				isCorrect = false;
				break;
			}
		}
		if (isCorrect) {
			result += d+1;
		}
	}
	cout << result << endl;
	return 0;
}