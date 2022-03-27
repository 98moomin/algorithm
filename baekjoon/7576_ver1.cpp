#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int arr[1001][1001];
bool visited[1001][1001];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

queue<pair<int, int> > q;

int M, N;

void bfs() {
    while (!q.empty()) {
        int x = get<1>(q.front());
        int y = get<0>(q.front());
        q.pop();
        int tmpx, tmpy;
        for (int i = 0; i < 4; i++) {
            tmpx = x + dx[i];
            tmpy = y + dy[i];
            if (!visited[tmpy][tmpx] && tmpx >= 0 && tmpx < M && tmpy >= 0 && tmpy < N && arr[tmpy][tmpx] == 0) {
                arr[tmpy][tmpx] = arr[y][x] + 1;
                q.push({tmpy, tmpx});
                visited[tmpy][tmpx] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    bfs();

    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                cout << "-1";
                return 0;
            }
            if (arr[i][j] > result)
                result = arr[i][j];
        }
    }

    cout << result - 1;

    return 0;
}