/*input
4
808
2133
999999999
1234599998
*/
#include <iostream>
#include <stdexcept>
using namespace std;

string s;

void increment(int k) {
	if (k > (int) s.size()-1) {
		throw invalid_argument("Index out of bounds");
	}
	if (k == -1) {
		s = "1"+s;
		return;
	}
	if (s[k] == '9') {
		s[k] = '0';
		increment(k-1);
	} else {
		s[k]++;
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{

		cin >> s;

		// Add 1 to s
		increment(s.size()-1);

		int j = -1;
		int n = s.size()-1;
		while (++j < s.size()/2) {

			if (s[j] >= s[n-j]) {
				s[n-j] = s[j];
			} else {
				if (j == n-j+1) {
					s[j]++; // s[j] can't be 9 because < s[n-j]
					s[n-j] = s[j];
				} else {
					increment(n-j-1);
					s[n-j] = s[j];
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}