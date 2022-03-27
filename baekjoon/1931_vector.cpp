#pragma warning(disable:4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, cnt;
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ e, s });
	}

	sort(v.begin(), v.end());

	int end = v[0].second;

	for (int i = 0; i < N; i++) {
		if (v[i].second >= end) {
			end = v[i].first;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}