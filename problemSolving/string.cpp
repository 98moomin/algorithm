#pragma warning(disable:4996)

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int T;
char tmp;
string str, prevS, nextS;

void prevString() {
	int firstC = str.length() - 1, secondC;
	while (firstC > 0) {
		if (str[firstC - 1] <= str[firstC])
			firstC--;
		else
			break;
	}
	if (firstC > 0) {
		secondC = firstC - 1;
		while (secondC + 1 <= str.length() - 1) {
			if (str[secondC + 1] < str[firstC - 1]) {
				secondC++;
			}
			else
				break;
		}
		tmp = prevS[firstC - 1];
		prevS[firstC - 1] = prevS[secondC];
		prevS[secondC] = tmp;
		reverse(prevS.begin() + firstC, prevS.end());
	}
	else {
		prevS = "-1";
	}
}

void nextString() {
	int firstC = 0, secondC;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] < str[i + 1])
			firstC = i;
	}
	if (firstC > 0) {
		for (int i = firstC + 1; i < str.length(); i++) {
			if (str[firstC] < str[i]) {
				secondC = i;
			}
		}
		tmp = nextS[firstC];
		nextS[firstC] = nextS[secondC];
		nextS[secondC] = tmp;
		reverse(nextS.begin() + firstC + 1, nextS.end());
	}
	else {
		nextS = "-1";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("string.inp", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> str;
		prevS = str, nextS = str;
		prevString();
		nextString();
		cout << prevS << " " << nextS << "\n";
	}

	return 0;
}