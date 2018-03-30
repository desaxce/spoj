/*input
25114
1111111111
3333333333
1
2
123
101010
0
*/
#include <iostream>
#include <vector>
#define pb push_back
#define ll long long
using namespace std;


ll solve(string s);

int main(int argc, char const *argv[])
{
	string s;

	while (getline(cin, s) and s != "0") {

		int n = s.size();
		int i = n - 1;

		vector<ll> dp(n+1, 0);
		dp[n] = 1;

		while (i >= 0) {
			if (s[i] == '0') { // case where we have 0XYZTUV
				i--;
				continue;
			} else {
				if (i==n-1) { // case where we have X
					dp[i] = 1;
					i--;
					continue;
				} else { 
					if (s[i+1] == '0') { // case where we have X0YZTUV (and X has to be equal to 1 or 2)
						dp[i] = dp[i+2];
					} else { // case where we have XYZTUV
						ll debut = stoi(s.substr(i, 2));
						dp[i] = dp[i+1];
						if (debut <= 26) {
							dp[i] += dp[i+2];
						}
					}
				}
			}
			i--;
		}
		
		printf("%lld\n", dp[0]);
	}
	return 0;
}