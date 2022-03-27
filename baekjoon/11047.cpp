#pragma warning(disable:4996)

#include <iostream>

using namespace std;

int N, K, cnt;
int arr[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		cnt += (K / arr[i]);
		K %= arr[i];
	}

	cout << cnt;

	return 0;
}