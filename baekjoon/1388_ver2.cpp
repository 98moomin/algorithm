#pragma warning(disable:4996)

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int cnt;
char arr[51][51];
bool visited[51][51];

void dfs(int x, int y) {
    visited[x][y] = true;
    int tmpx = x + 1;
    int tmpy = y + 1;
    if (arr[x][y] == '|') {
        if (arr[tmpx][y] == '|' && !visited[tmpx][y] && tmpx < N)
            dfs(tmpx, y);
    } else {
        if (arr[x][tmpy] == '-' && !visited[x][tmpy] && tmpy < M) {
            dfs(x, tmpy);
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