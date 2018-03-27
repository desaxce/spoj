/*input
1
5 3
1
2
8
4
9
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

		vector<int> distBetweenBoxes;

		// display(x);

		sort(x.begin(), x.end());
		// display(x);

		for (int j = 0; j < N-1; j++) {
			distBetweenBoxes.pb(x[j+1]-x[j]+1);
		}

		// display(distBetweenBoxes);
		sort(distBetweenBoxes.begin(), distBetweenBoxes.end());
		// display(distBetweenBoxes);
		reverse(distBetweenBoxes.begin(), distBetweenBoxes.end());
		display(distBetweenBoxes);

		// We get distBetweenBoxes = [5, 3, 2, 2]
		// The first index (0) allows for the placing of two cows (distance 5)
		// The second index (1) allows for the placing of 1 additional cow, etc
		// Hence the index we're looking for is C-2
		// (1 because array is 0-based, 1 because the first index allows the placing of two cows)
		printf("%d\n", distBetweenBoxes[C-2]);

	}
	return 0;
}