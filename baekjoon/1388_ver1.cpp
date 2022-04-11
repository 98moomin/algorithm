#pragma warning(disable:4996)

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int cnt;
char arr[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool visited[51][51];

void dfs(int x, int y) {
    visited[x][y] = true;
    if (arr[x][y] == '-') {
        for (int i = 0; i < 4; i++) {
            int tmpy = y + dy[i];
            if (arr[x][tmpy] == '-' && !visited[x][tmpy] && 0 <= tmpy && tmpy < M) {
                dfs(x, tmpy);
            }
        }
    } else {
        for (int i = 0; i < 4; i++) {
            int tmpx = x + dx[i];
            if (arr[tmpx][y] == '|' && !visited[tmpx][y] && 0 <= tmpx && tmpx < N) {
                dfs(tmpx, y);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}
