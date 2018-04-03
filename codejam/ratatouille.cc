/*input
6
2 1
500 300
900
660
2 1
500 300
1500
809
2 2
50 100
450 449
1100 1101
2 1
500 300
300
500
1 8
10
11 13 17 11 16 14 12 18
3 3
70 80 90
1260 1500 700
800 1440 1600
1700 1620 900
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define pb push_back
#define ll long long

using namespace std;

struct Intervalle
{
	ll debut;
	ll fin;

	Intervalle () {

	}
	Intervalle(ll debut, ll fin) {
		this->debut = debut;
		this->fin = fin;
	}

};

struct IntervallComparator
{
	bool operator()(const Intervalle& i1, const Intervalle& i2) {
		return (i1.debut > i2.debut) or ((i1.debut == i2.debut) and (i1.fin > i2.fin));
	}
};

int main(int argc, char const *argv[])
{
	ll T;
	scanf("%lld", &T);

	for (ll i = 0; i < T; ++i)
	{
		printf("Case #%lld: ", i+1);
		ll N, P;

		scanf("%lld %lld", &N, &P);
		
		vector<ll> R(N);
		
		for (ll j = 0; j < N; ++j) {
			ll temp;
			scanf("%lld", &temp);
			R[j] = temp;
		}

		vector< priority_queue<Intervalle, vector<Intervalle>, IntervallComparator> > Q(N);
		for (ll j = 0; j < N; j++) {
			Q[j] = priority_queue<Intervalle, vector<Intervalle>, IntervallComparator>();

			for (ll k = 0; k < P; k++) {
				ll temp;
				scanf("%lld", &temp);

		
				Q[j].push(Intervalle(ceil(100.*temp/110/R[j]), floor(100*temp/90/R[j])));
				// cout << ceil(100.*temp/110/R[j]) << "," << floor(100*temp/90/R[j]) << endl;
				// cout << Q[j][k].debut << "," << Q[j][k].fin  << " ";
			}			
			// cout << endl;
		}

		// for (ll j = 0; j < N; j++) {
		// 	while(!Q[j].empty()) {
		// 		printf("(%lld, %lld)\t", Q[j].top().debut, Q[j].top().fin);
		// 		Q[j].pop();
		// 	}
		// 	printf("\n");
		// }

		bool isOk = true;
		ll cnt = 0;
		while (isOk) {
			
			ll debut = Q[0].top().debut;
			ll fin = Q[0].top().fin;

			for (ll j = 0; j < N; j++) {
				debut = max(Q[j].top().debut, debut);
				fin = min(Q[j].top().fin, fin);
			}

			if (debut <= fin) {
				cnt++;
				for (ll j = 0; j < N; j++) {
					Q[j].pop();
				}
			} else {
				ll minimum = 0;

				for (ll j = 0; j < N; j++) {
					if ((Q[j].top().debut < Q[minimum].top().debut) or ((Q[j].top().debut == Q[minimum].top().debut) and (Q[j].top().fin < Q[minimum].top().fin))) {
						minimum = j;
					}
				}
				Q[minimum].pop();
			}

			for (ll j = 0; j< N; j++) {
				if (Q[j].empty()) {
					isOk = false;
				}
			}
		}
		cout << cnt << endl;

		
	}
	return 0;
}
