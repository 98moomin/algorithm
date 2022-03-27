#pragma warning(disalbe:4996)
#include<iostream>

using namespace std;

int N, cnt = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int j = i;
		while (j) {
			cnt = (j % 10 == 3 || j % 10 == 6 || j % 10 == 9) ? cnt + 1 : cnt;
			j /= 10;
		}
	}

	cout << cnt;
	
	return 0;
}