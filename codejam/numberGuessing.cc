#include <iostream>
#include <math.h>
#define pb push_back
#define ll long long

using namespace std;

const string correct = "CORRECT";
const string tooSmall = "TOO_SMALL";
const string tooBig = "TOO_BIG";

int main(int argc, char const *argv[])
{
	ll t;
	scanf("%lld", &t);
	// printf("t = %lld\n", t);

	for (ll i = 0; i < t; ++i)
	{
		ll a, b, n;

		scanf("%lld %lld", &a, &b);
		// printf("a = %lld and b = %lld\n", a, b);

		scanf("%lld", &n);
		// printf("n = %lld\n", n);
		a = a+1; // We don't want to have exclusive bounds

		// Now let's find p in [a, b]

		bool isCorrect = false;

		while (!isCorrect) {

			ll m = a + ((b-a)/2);
			// cerr << m << endl;
			printf("%lld\n", m);

			string response;
			cin >> response;

			if (response == correct) {
				isCorrect = true;
			} else if (response == tooSmall) {
				a = m+1;
			} else if (response == tooBig) {
				b = m-1;
			}
		}
	}
	return 0;
}