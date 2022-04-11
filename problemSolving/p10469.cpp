#pragma warning(disable:4996)

#include <iostream>

unsigned int a, b, c;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("p10469.inp", "r", stdin);
	freopen("p10469.out", "w", stdout);


	while (1) {
		cin >> a >> b;
		if (cin.eof())
			break;
		c = a ^ b;
		cout << c << "\n";
	}


	return 0;
}