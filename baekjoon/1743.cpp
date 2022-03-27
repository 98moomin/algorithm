#pragma warning(disable:4996)

#include <iostream>
#include <queue>

using namespace std;

int N, M, K, result, cnt;
int arr[101][101];
bool visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;

void bfs(int a, int b) {
    cnt = 1;
    visited[a][b] = true;
    q.push({a, b});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tmpx = x + dx[i];
            int tmpy = y + dy[i];
            if (arr[tmpx][tmpy] == 1 && !visited[tmpx][tmpy] && 0 <= tmpx && 0 <= tmpy && tmpx < N && tmpy < M) {
                q.push({tmpx, tmpy});
                visited[tmpx][tmpy] = true;
                cnt++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        arr[r - 1][c - 1] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 1 && !visited[i][j]) {
                bfs(i, j);
                result = result < cnt ? cnt : result;
            }
        }
    }

    cout << result;

    return 0;
}