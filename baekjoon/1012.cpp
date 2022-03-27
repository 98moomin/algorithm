#pragma warning(disable:4996)
#include <iostream>
#include <cstring>

using namespace std;

int T, M, N, K, cnt;
int arr[51][51];
bool visited[51][51];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int tmpx = x + dx[i];
        int tmpy = y + dy[i];
        if (!visited[tmpx][tmpy] && tmpx >= 0 && tmpy >= 0 && tmpx < M && tmpy < N && arr[tmpx][tmpy] == 1)
            dfs(tmpx, tmpy);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> M >> N >> K;
        int x, y;
        for (int i = 0; i < K; i++) {
            cin >> x >> y;
            arr[x][y] = 1;
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
        cnt = 0;
    }

    return 0;
}
