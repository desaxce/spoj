/*input
2
5 3
1
2
8
4
9
6 4
1
11
21
22
40
41
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;

void display(vector<int> x) {
	for (int i = 0; i < x.size(); ++i)
	{
		printf("%d, ", x[i]);
	}
	printf("\n");
}

bool isDistanceAcceptable(int C, int d, vector<int> stalls) {
	int lastCowStall = stalls[0];
	C = C-1;
	int i = 1;
	while (i < stalls.size() and C != 0) {
		if (stalls[i] - lastCowStall >= d) {
			C = C-1;
			lastCowStall = stalls[i];
		}
		i++;
	}
	return C==0;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; ++i)
	{
		int N, C;
		scanf("%d %d", &N, &C);

		vector<int> x;

		for (int j = 0; j < N; ++j)
		{
			int temp;
			scanf("%d", &temp);
			x.pb(temp);
		}

		sort(x.begin(), x.end());

		int a = 1;
		int b = x[x.size()-1];

		int m = (b-a)/2;

		while (a != m) {
			if (isDistanceAcceptable(C, m, x)) {
				a = m;
			} else {
				b = m;
			}
			m = a+(b-a)/2;
		}

		printf("%d\n", a);		

	}
	return 0;
}