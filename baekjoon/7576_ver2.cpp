#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int arr[1001][1001];
int days[1001][1001];
bool visited[1001][1001];
queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tmpx = x + dx[i];
            int tmpy = y + dy[i];
            if (tmpx >= 0 && tmpy >= 0 && tmpx < M && tmpy < N && !visited[tmpx][tmpy] && arr[tmpx][tmpy] == 0) {
                q.push({tmpx, tmpy});
                arr[tmpx][tmpy] = 1;
                days[tmpx][tmpy] = days[x][y] + 1;
                visited[x][y] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push({i, j});
                visited[i][j] = true;
                days[i][j] = 1;
            }
        }
    }

    bfs();

    int MAX = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (days[i][j] > MAX)
                MAX = days[i][j];
            if (arr[i][j] != -1 && days[i][j] == 0) {
                cout << "-1";
                return 0;
            }
        }
    }

    cout << MAX - 1;

    return 0;
}
