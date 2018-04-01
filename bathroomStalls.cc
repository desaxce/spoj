/*input
6
4 2
5 2
6 2
1000 1000
1000 1
100000000000000000 5000000000000000
*/
#include <iostream>
#include <map>

#define ll long long

using namespace std;

map<ll, ll> spaces;

int main(int argc, char const *argv[])
{
	ll T;

	scanf("%lld", &T);

	for (int i = 0; i < T; ++i)
	{
		ll N, K;
		scanf("%lld %lld", &N, &K);
		spaces.clear();
		spaces[N]++;

		ll left;
		ll right;
		while (K > 0) {
			auto it = prev(spaces.end()); // takes the one with biggest key
			ll size = it->first;
			ll count = it->second;
			spaces.erase(it);

			left = (size-1)/2; // because we take the left most stall
			right = size/2;
			spaces[left] += count;
			spaces[right] += count;

			K -= count; // not a big deal if K becomes negative ==> we still have the correct left and right values
		}
		printf("Case #%lld: %lld %lld\n", i+1, max(left, right), min(left, right));
	}
	return 0;
}

