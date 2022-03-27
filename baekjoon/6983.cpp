#pragma warning(disable:4996)

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct result {
	int x;
	int y;
} result;

result r;

int T, m, n, K;
string str;
char c;
char arr[51][51];
bool flag, check;
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

void dfs(int y, int x, int cnt, int way) {
	if (cnt == str.size()) {
		cout << r.x + 1 << " " << r.y + 1 << "\n";
		check = true;
		return;
	}

	for (int i = 0; i < 8; i++) {
		int tmpx = x + dx[i];
		int tmpy = y + dy[i];
		if (0 <= tmpx && tmpx < n && 0 <= tmpy && tmpy < m && arr[tmpy][tmpx] == str[cnt] && (way == -1 || way == i)) {
			dfs(tmpy, tmpx, cnt + 1, i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> m >> n;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> c;
				arr[i][j] = c >= 'a' ? c - 32 : c;
			}
		}
		cin >> K;
		for (int k = 0; k < K; k++) {
			flag = false;
			check = false;
			cin >> str;
			for (int i = 0; i < str.length(); i++) {
				str[i] = str[i] >= 'a' ? str[i] - 32 : str[i];
			}
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (str[0] == arr[i][j]) {
						r.x = i, r.y = j;
						dfs(i, j, 1, -1);
						if (check) {
							flag = true;
							break;
						}
					}
				}
				if (flag)
					break;
			}
			if (!check)
				cout << m << " " << n << "\n";
		}
		cout << "\n";
	}

	return 0;
}