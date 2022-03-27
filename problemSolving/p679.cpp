#pragma warning(disable:4996)

#include <iostream>

using namespace std;

int T, D, I, P;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("p679.inp", "r", stdin);
	freopen("p679.out", "w", stdout);

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> D >> I;
		P = 1;
		for (int i = 0; i < D - 1; i++) {
			if (I % 2) {
				I = (I + 1) / 2;
				P *= 2;
			}
			else {
				I /= 2;
				P = P * 2 + 1;
			}
		}
		cout << P << "\n";
	}

	return 0;
}
