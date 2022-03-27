#pragma warning(disalbe:4996)
#include <iostream>
#include <string>

using namespace std;

int N;
string str;

bool isPalin(int idx) {
	for (int i = 0; i < (str.size() - idx) / 2; i++) {
		if (str[i + idx] != str[str.size() - 1 - i])
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (isPalin(i)) {
			cout << str.size() + i;
			break;
		}
	}

	return 0;
}