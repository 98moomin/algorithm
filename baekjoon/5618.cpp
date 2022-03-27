#pragma warning(disalbe:4996)
#include<iostream>

using namespace std;

int N, MAX = 0;
int arr[3];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		MAX = (MAX < arr[i]) ? arr[i] : MAX;
	}

	for (int i = 1; i <= MAX; i++) {
		bool ch = true;
		for (int j = 0; j < N; j++) {
			if (arr[j] % i != 0) {
				ch = false;
			}
		}
		if (ch)
			cout << i << "\n";
	}

	return 0;
}