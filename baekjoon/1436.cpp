#pragma warning(disalbe:4996)
#include <iostream>
#include <string>

using namespace std;

int N;
string tmp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int start = 665;

	for (int i = 0; i < N; i++) {
		while (1) {
			start++;
			tmp = to_string(start);
			if (tmp.find("666") != -1)
				break;
		}
	}

	cout << start;

	return 0;
}