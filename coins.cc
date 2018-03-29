/*input
12
2
1000000000
*/
#include <iostream>
#include <unordered_map>
#define ll long long
using namespace std;

ll solve(ll n);

unordered_map<ll, ll> dollars;

int main(int argc, char const *argv[])
{
	ll n; // less than 10^9

	while(scanf("%lld", &n) == 1) {
		dollars[0] = 0L;
		printf("%lld\n", solve(n));
	}

	return 0;
}

ll solve(ll n) {
	if (dollars.find(n) != dollars.end()) {
		return dollars[n];
	}
	ll total = solve(n/2) + solve(n/3) + solve(n/4);

	dollars[n] = total > n? total: n;
	return dollars[n];
}