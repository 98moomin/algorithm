#pragma warning(disalbe:4996)
#include <iostream>

using namespace std;

int N, K;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (N % i == 0)
			cnt++;
		if (cnt == K) {
			cout << i;
			break;
		}
	}

	if (cnt < K)
		cout << "0";
	
	return 0;
}