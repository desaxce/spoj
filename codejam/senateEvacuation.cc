/*input
4
2
2 2
3
3 2 2
3
1 1 2
3
2 3 1
*/
#include <iostream>
#include <queue>

#define ll long long
#define pb push_back

using namespace std;

//helper function displays sorted data
template<class T>
void printQueue(T& q)
{
	T q1 = q;
    while (!q1.empty())
    {
        printf("%c (%lld), ", q1.top().partyName, q1.top().numberOfMembers);
        q1.pop();
    }
    printf("\n");
}

struct Party {
	char partyName;
	ll numberOfMembers;

	Party (char partyName, ll numberOfMembers) {
		this->partyName = partyName;
		this->numberOfMembers = numberOfMembers;
	}
};

struct PartyComparator {
	bool operator()(const Party& p1, const Party& p2) {
		return p1.numberOfMembers < p2.numberOfMembers;
	}
};

int main(int argc, char const *argv[])
{
	ll t;
	scanf("%lld", &t);

	for (ll i = 0; i < t; ++i)
	{
		printf("Case #%lld:", i+1);
		ll N;
		scanf("%lld", &N);

		priority_queue<Party, vector<Party>, PartyComparator> senate;

		for (int j = 0; j < N; ++j)
		{
			ll temp;
			scanf("%lld", &temp);
			senate.push(Party((char) ('A'+j), temp));
		}

		while (!senate.empty()) {
			printf(" ");
			Party p1 = senate.top();

			if (senate.size() == 3 and p1.numberOfMembers == 1) {
				printf("%c", p1.partyName);
				senate.pop();
			} else { // We are certain to have more than only one party (otherwise he'd have a majority!)
				senate.pop();
				Party p2 = senate.top();
				senate.pop();

				printf("%c%c", p1.partyName, p2.partyName);

				p1.numberOfMembers--;
				p2.numberOfMembers--;

				if (p1.numberOfMembers != 0) {
					senate.push(p1);
				}
				if (p2.numberOfMembers != 0) {
					senate.push(p2);
				}
			}
		}

		if (i < t-1) {
			printf("\n");
		}
	}
	return 0;
}