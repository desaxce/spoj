/*input
3
2525 1
2400 5
300 2
120 60
60 90
100 2
80 100
70 10
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long

using namespace std;

int main(int argc, char const *argv[])
{
	ll t;
	scanf("%lld", &t);

	for (ll i = 0; i < t; ++i)
	{
		printf("Case #%lld:", i+1);
		ll D, N;
		scanf("%lld %lld", &D, &N);
		vector<double> temps;

		for (ll j = 0; j < N; ++j)
		{
			ll K, S;
			scanf("%lld %lld", &K, &S);
			temps.pb((D-K)*1.0/S);
		}
		sort(temps.begin(), temps.end());
		printf(" %.8f\n", D/temps[temps.size()-1]);
	}
	return 0;
}