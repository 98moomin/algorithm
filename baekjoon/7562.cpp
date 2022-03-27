#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T, l, startx, starty, endx, endy;
bool visited[301][301];
int result[301][301];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
queue<pair<int, int>> q;

void init() {
    while (!q.empty())
        q.pop();
    memset(result, 0, sizeof(result));
    memset(visited, false, sizeof(visited));
}

void bfs(int a, int b) {
    q.push({a, b});
    visited[a][b] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == endx && y == endy) {
            cout << result[x][y] << "\n";
            break;
        }
        for (int i = 0; i < 8; i++) {
            int tmpx = x + dx[i];
            int tmpy = y + dy[i];
            if (0 <= tmpx && tmpx < l && 0 <= tmpy && tmpy < l && !visited[tmpx][tmpy]) {
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

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> l;
        cin >> startx >> starty;
        cin >> endx >> endy;
        bfs(startx, starty);
        init();
    }

    return 0;
}