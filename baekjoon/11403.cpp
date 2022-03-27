#pragma warning(disable:4996)

#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[101][101];
bool visited[101][101];
int result[101][101];

void dfs(int x, int y) {
    for (int i = 0; i < N; i++) {
        if (arr[x][i] == 1 && !visited[x][i]) {
            visited[x][i] = true;
            result[y][i] = 1;
            dfs(i, y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        dfs(i, i);
        memset(visited, false, sizeof(visited));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}