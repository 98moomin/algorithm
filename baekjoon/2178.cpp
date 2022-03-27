#pragma warning(disable:4996)

#include <iostream>
#include <queue>

using namespace std;

int N, M;
char arr[101][101];
int result[101][101] = {1,};
bool visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;

void bfs() {
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tmpx = x + dx[i];
            int tmpy = y + dy[i];
            if (tmpx >= 0 && tmpy >= 0 && tmpx < N && tmpy < M && arr[tmpx][tmpy] == '1' && !visited[tmpx][tmpy]) {
                q.push({tmpx, tmpy});
                visited[tmpx][tmpy] = true;
                result[tmpx][tmpy] = result[x][y] + 1;
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

    bfs();

    cout << result[N - 1][M - 1];

    return 0;
}